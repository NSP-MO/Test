#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TWEET 1000
#define MAX_HASHTAG 100
#define MAX_LENGTH 255
struct HashtagCount {
    char hashtag[MAX_LENGTH];
    int count;
    int firstAppearance;
};
void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void extractHashtags(char *tweet, struct HashtagCount hashtags[], int *hashtagCount, int tweetNumber) {
    char *token = strtok(tweet, " \n");
    
    while(token != NULL) {
        if(token[0] == '#') {
            char cleanTag[MAX_LENGTH];
            strcpy(cleanTag, token + 1);
            toLowerCase(cleanTag);
            
            int found = 0;
            for(int i = 0; i < *hashtagCount; i++) {
                if(strcmp(hashtags[i].hashtag, cleanTag) == 0) {
                    hashtags[i].count++;
                    found = 1;
                    break;
                }
            }
            
            if(!found && *hashtagCount < MAX_HASHTAG) {
                strcpy(hashtags[*hashtagCount].hashtag, cleanTag);
                hashtags[*hashtagCount].count = 1;
                hashtags[*hashtagCount].firstAppearance = tweetNumber;
                (*hashtagCount)++;
            }
        }
        token = strtok(NULL, " \n");
    }
}

int main() {
    char tweet[MAX_LENGTH];
    struct HashtagCount hashtags[MAX_HASHTAG] = {0};
    int hashtagCount = 0;
    int tweetNumber = 0;
    
    while(fgets(tweet, MAX_LENGTH, stdin)) {
        extractHashtags(tweet, hashtags, &hashtagCount, tweetNumber);
        tweetNumber++;
    }
    
    int maxCount = 0;
    int earliestAppearance = MAX_TWEET;
    char mostPopular[MAX_LENGTH] = "";
    
    for(int i = 0; i < hashtagCount; i++) {
        if(hashtags[i].count > maxCount || 
           (hashtags[i].count == maxCount && 
            hashtags[i].firstAppearance < earliestAppearance)) {
            maxCount = hashtags[i].count;
            earliestAppearance = hashtags[i].firstAppearance;
            strcpy(mostPopular, hashtags[i].hashtag);
        }
    }
    
    printf("%s\n", mostPopular);
    
    return 0;
}