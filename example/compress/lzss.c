#include<stdio.h>
#include<stdlib.h>
#define MST_COMPRESS_IMPLEMENTATION
#include"../../compress.h"

int main(){
    #define t "abababcdabcabcdc"// 4 11
    #define p "abcd"
    /* #define t "WelcometotheworldofhiddenmessagesandcodedtextsIfyourereadingthisyouhavesuccessfullyfoundthesecretphraseembeddedwithinthisparagraphThisisatesttoseeifautomatedsystemscandetectspecificsequenceslikeifyouarereadingthisThephraseifyouarereadingthisappearsmultipletimesforredundancyEngineersusesuchpatternstoverifydatatransmissionortestsearchalgorithmsifyouarereadingthisisnotjustasentenceitisasignalEvenifthetextseemsordinarythepresenceofifyouarereadingthismarksitasintentionalPleasecontinuetoreadingtoensurefullcomprehensionDetectionofsubstringsisessentialinprogrammingandcybersecurityRememberifyouarereadingthisyouareontherighttrackThankyouforyourattentiontodetail" */
    /* #define p "ifyouarereadingthis" */
    /* list.members = malloc(sizeof(list.members[0]) * 4); */
    size_t *list = NULL;
    list = malloc(sizeof(list[0]) * sizeof(p));
    printf(
        "%zu,4\n",
        longest_match(
            t,sizeof(t),
            p,sizeof(p),
            list
        )
    );
    return 0;
}
