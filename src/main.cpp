#include <stdio.h>
#include <iostream>
#define BUFLEN (100)

#include "../includes/JsonParser.h"

using namespace std;

//int main(void) {
////    char *json[] = {
////            "{\"Session ID\":\"2132\"}",
////    };
////    char key[BUFLEN];
////    char val[BUFLEN];
////
////    for(int i=0; i<sizeof(json)/sizeof(char *); i++) {
////        sscanf(json[i], "{\"%[^\"]\":\"%[^\"]\"}", key, val);
////        cout << "The value of " << key << " is " << val;
////    }
////
//       return 0;
//}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
