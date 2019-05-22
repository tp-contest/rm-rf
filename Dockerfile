FROM gcc:latest as build

# Установим рабочую директорию для сборки GoogleTest
WORKDIR /gtest_build

RUN apt-get update && \
    apt-get install -y \
      libboost-dev \
      libgtest-dev \
      cmake \
    && \
    cmake -DCMAKE_BUILD_TYPE=Release /usr/src/gtest && \
    cmake --build . && \
    mv lib*.a /usr/lib

# Скопируем директорию /src в контейнер
ADD ./src /app/src

# Установим рабочую директорию для сборки проекта
WORKDIR /app/build

# Выполним сборку нашего проекта, а также его тестирование
RUN cmake ../src && \
    cmake --build . 

FROM ubuntu:latest

# чтоб не под root'ом
RUN groupadd -r sample && useradd -r -g sample sample
USER sample

# Установим рабочую директорию
WORKDIR /app

# Скопируем приложение со сборочного контейнера в рабочую директорию
COPY --from=build /app/build/prj .

# Установим точку входа
ENTRYPOINT ["./prj"]