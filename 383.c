#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int filled[26] = {0};
    bool result = true;
    for(int i = 0;magazine[i] >= 'a' && magazine[i] <= 'z';i++){
        filled[magazine[i]-'a']++;
    }

    for(int i = 0;ransomNote[i] >= 'a' && ransomNote[i] <= 'z';i++){
        if(filled[ransomNote[i]-'a'] <= 0){
            result = false;
            break;
        }else{
            filled[ransomNote[i]-'a']--;
        }
    }
    return result;
}

int main(){
    char ransomNote[] = "adedcdvwsefsdfd";
    char magazine[] = "afghfnvnvbwsefsjhmnbh";
    printf("%d",canConstruct(ransomNote,magazine));
}