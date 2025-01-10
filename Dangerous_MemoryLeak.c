#include <stdio.h>

#include <string.h>

#define MAX 1000

char str[MAX] = " This \t program is \t\t intended to test \t\t\t\t";   
 
// char *entab(char *);
char *detab(char *);

// entab and detab
int main(int argc, char *argv[]) {
    printf("%s \n", str);

    char *de_str = detab(str);
    for (int i = 0; strlen(str); i++) {
        if (de_str[i] == ' ') 
            printf("%d", de_str[i]);
        
        printf("%c", de_str[i]);
    }

}

char *detab(char *str) {
    int n=3;
    int i=0, j=0;

    char re[MAX];
    
    for ( i=0; str[i] != '\0'; i++ ) {
        if (str[i] == '\t'){
            int t=n;
            while (--t) {
                re[j++] = ' ';
            }
        }
        else {
            re[j++] = str[i];
        }
    }

    re[j] = '\0';
    printf("%d", j);
    printf("%s", re[j]);

    return re;
}
    


char *entab(char *str) {
    int i, j, k;
    char *new_str;

    j = 0;

    for (i = 0; str[i]!= '\0'; i++) {
        if (str[i] == '\t') {
            for (k = 0; k < 4; k++) {
                new_str[j++] = str[i];
            }
        } else {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';

    return new_str;
}

/*
 This    program is              intended to test                                
32 This32 32 32 32 program
                          s���32 ��D_��/����1�����0����I����������0����\P��P��1������\��D_��D_�\�1���`3���h3�����������1���32 �D_���D_�0�3����2���`1�������`1���s\������D_���J���������1���ڭ����D_�p2���H��3���`3����J32(2���h4����J�J�2����ˍ
                                                                  �`�
                                                                     �`�
                                                                        7ӊ
                                                                          0�2������2��D_���J��D_���Jp2���y\����D_��2���Q|��`�K���
                                                                                                                                 ��J`�
                                                                                                                                      �3���Yp���2���0@K7ȻD_��K`3���9��
                                                                                                                                                                      �K���
                                                                                                                                                                          �.���a��K�Kh4�����
                 `�
                   0�3����2����.���a��3�����J�3���/����4����4���.��
                                                                   ���
                                                                      B���
                                                                          pa�
                                                                             @4�����
                                                                                    ��
                                                                                      ���
                                                                                         @���
                                                                                             �a�
                                                                                                ��
                                                                                                  @4���0w��
                                                                                                           ���
9���9���29���X9����9����9����9����9����9���':���p:����:����:����:���                                          �J�6����6����6����6���7���(7���h7���z7����8���
                                                                    ;���.;���>;���V;����;����;����;����;���<���"<���3<���G<����<���<=���[=����=���5>���H>���a>���>����>����6����>����>���?���F?���c?����?����?����?���
executable_path=./a.out./a.outUSER=choyuiyipMallocNanoZone=0__CFBundleIdentifier=com.microsoft.VSCodeCOMMAND_MODE=unix2003DISPLAY=/private/tmp/com.apple.launchd.yqdYDmi0xy/org.xquartz:0LOGNAME=choyuiyipPATH=/usr/local/Cellar/pyenv-virtualenv/1.2.3/shims:/Users/choyuiyip/.pyenv/shims:/usr/local/platform-tools:/usr/local/bin:/usr/local/sbin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/Library/Apple/usr/bin:/usr/local/Cellar/pyenv-virtualenv/1.2.3/shims:/usr/local/platform-tools:/usr/local/sbin:/Users/choyuiyip/.cargo/binSSH_AUTH_SOCK=/private/tmp/com.apple.launchd.OX4ThoIxWb/ListenersSHELL=/bin/zshHOME=/Users/choyuiyip__CF_USER_TEXT_ENCODING=0x1F5:0x0:0x2TMPDIR=/var/folders/_5/4n7xwz9n70n3ms3dnx2jywvw0000gn/T/XPC_SERVICE_NAME=0XPC_FLAGS=0x0ORIGINAL_XDG_CURRENT_DESKTOP=undefinedSHLVL=1PWD=/Users/choyuiyip/Programming/C_Prog/Playground/C_Programming_BookOLDPWD=/Users/choyuiyip/Programming/C_Prog/Playground/C_Programming_BookHOMEBREW_PREFIX=/usr/localHOMEBREW_CELLAR=/usr/local/CellarHOMEBREW_REPOSITORY=/usr/local/HomebrewINFOPATH=/usr/local/share/info:/usr/local/share/info:PYENV_ROOT=/Users/choyuiyip/.pyenvPYENV_SHELL=zshPYENV_VIRTUALENV_INIT=1GOOGLE_APPLICATION_CREDENTIALS=/etc/google/test-f3464-firebase-adminsdk-rkob1-05d762f90b.jsonNVM_DIR=/Users/choyuiyip/.nvmNVM_CD_FLAGS=-qNVM_RC_VERSION=TERM_PROGRAM=vscodeTERM_PROGRAM_VERSION=1.96.0LANG=en_US.UTF-8COLORTERM=truecolorGIT_ASKPASS=/Applications/Visual32 Studio32 Code.app/Contents/Resources/app/extensions/git/dist/askpass.shVSCODE_GIT_ASKPASS_NODE=/Applications/Visual32 Studio32 Code.app/Contents/Frameworks/Code32 Helper32 (Plugin).app/Contents/MacOS/Code32 Helper32 (Plugin)VSCODE_GIT_ASKPASS_EXTRA_ARGS=VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual32 Studio32 Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.jsVSCODE_GIT_IPC_HANDLE=/var/folders/_5/4n7xwz9n70n3ms3dnx2jywvw0000gn/T/vscode-git-ff50dbae6a.sockVSCODE_INJECTION=1ZDOTDIR=/Users/choyuiyipUSER_ZDOTDIR=/Users/choyuiyipTERM=xterm-256color_=/Users/choyuiyip/Programming/C_Prog/Playground/C_Programming_Book/./a.outptr_munge=main_stack=
                                                                    */