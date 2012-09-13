#include "wchar_opp.h"
#include <stdio.h>
#include <locale.h>

int main(int argc, const char *argv[])
{
    wchar_t wc1 = L'h';
    printf("%s\n", wchartochar(wc1));
    
    /*为什么一定要调用setlocale呢？参考，实际不同
     * 因为在C/C++语言标准中定义了其运行时的字符集环境为"C"，也就是ASCII字符集的一个子集，那么mbstowcs在工作时会将cstr中所包含的字符串看作是ASCII编码的字符，而不认为是一个包含有chs编码的字符串，所以他会将每一个中文拆成2个ASCII编码进行转换，这样得到的结果就是会形成4个wchar_t的字符组成的串，那么如何才能够让mbstowcs正常工作呢？在调用mbstowcs进行转换之间必须明确的告诉mbstowcs目前cstr串中包含的是chs编码的字符串，通过setlocale(LC_ALL, "chs")函数调用来完成，需要注意的是这个函数会改变整个应用程序的字符集编码方式，必须要通过重新调用setlocale(LC_ALL, "C")函数来还原，这样就可以保证mbstowcs在转换时将cstr中的串看作是中文串，并且转换成为2个wchar_t字符，而不是4个。 
     */
    if (!setlocale(LC_CTYPE, "")) {
        fprintf(stderr, "Can't set the specified locale! "
                "Check LANG, LC_CTYPE, LC_ALL.\n");
        return 1;
    }
    
    //wchar_t * wc2 = L"钓鱼岛是中国的!"; - 不要以明码的方式书写，禁忌！
    //用UltaEdit得到编码写入；
    wchar_t * wc2 = L"\u9493\u9C7C\u5C9B\u662F\u4E2D\u56FD\u7684!";
    printf("%s\n", wcharstochar(wc2));

    printf("%lc\n", chartowchar('h'));
    //一个汉字3个字节 22
    wchar_t * pWch = charstowchar("钓鱼岛是中国的!");
    printf("%ls\n", pWch); 
    //------------------- 
    //一个汉字3个字节，转换为wchar_t时，一个汉字就会占了3 + 1个字节，1个字节为了对其；因此每个汉字占了pWch数组的两个个数！难道这就是传说中的对齐，我想了很久，经过很多测试发现如下打印可以正确打印，因此应该没问题，再理解！一天了，亲！
    printf("%lc", pWch[0]);
    //printf("%lc", pWch[1]);
    printf("%lc", pWch[2]);
    //printf("%lc", pWch[3]);
    printf("%lc", pWch[4]);
    //printf("%lc", pWch[5]);
    printf("%lc", pWch[6]);
    //printf("%lc", pWch[7]);
    printf("%lc", pWch[8]);
    //printf("%lc", pWch[9]);
    printf("%lc", pWch[10]);
    //printf("%lc", pWch[11]);
    printf("%lc", pWch[12]);
    //printf("%lc", pWch[13]);
    printf("%lc\n", pWch[14]);

    //还原字符集编码方式,可以不用
    if (!setlocale(LC_CTYPE, "C")) {
        fprintf(stderr, "Can't back locale! "
                "Check LANG, LC_CTYPE, LC_ALL.\n");
        return 1;
    }

    return 0;
}
