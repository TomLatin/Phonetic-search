#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;
using namespace std;


TEST_CASE("Words without confusion") {
    string text = " t tom latin blue sky encyclopedia good talk true  pseudopseudohypoparathyroidism  tobacco Chrononhotonthologos Honorificabilitudinitatibus electroencephalographically semihemidemisemihemidemisemihemidemisemiquaver";
    /*1*/ CHECK(find(text, "t") == string("t"));
    /*2*/ CHECK(find(text, "tom") == string("tom"));
    /*3*/ CHECK(find(text, "latin") == string("latin"));
    /*4*/ CHECK(find(text, "blue") == string("blue"));
    /*5*/ CHECK(find(text, "sky") == string("sky"));
    /*6*/ CHECK(find(text, "good") == string("good"));
    /*7*/ CHECK(find(text, "talk") == string("talk"));
    /*8*/ CHECK(find(text, "true") == string("true"));
    /*9*/ CHECK(find(text, "encyclopedia") == string("encyclopedia"));
    /*10*/  CHECK(find(text, "Honorificabilitudinitatibus") == string("Honorificabilitudinitatibus"));
    /*11*/   CHECK(find(text, "electroencephalographically") == string("electroencephalographically"));
    /*12*/   CHECK(find(text, "semihemidemisemihemidemisemihemidemisemiquaver") == string("semihemidemisemihemidemisemihemidemisemiquaver"));
    /*13*/   CHECK(find(text, "pseudopseudohypoparathyroidism") == string("pseudopseudohypoparathyroidism"));
    /*14*/   CHECK(find(text, "Chrononhotonthologos") == string("Chrononhotonthologos"));
    /*15*/   CHECK(find(text, "tobacco") == string("tobacco"));
}

TEST_CASE("Test replacement of v and w & replacement of w and v")
{
    string textVtoW = " w wolwo wiwi wife waluelessnesses viwisectionists semihemidemisemihemidemisemihemidemisemiquawer";
    string textWtoV="v vvvvw walid volvo wvwv viwi semihemidemisemihemidemisemihemidemisemiquaver vivisectionists";
    /*1*/ CHECK(find(textVtoW, "v") == string("w"));
    /*2*/ CHECK(find(textVtoW, "valuelessnesses") == string("waluelessnesses"));
    /*3*/ CHECK(find(textVtoW, "vivisectionists") == string("viwisectionists"));
    /*4*/ CHECK(find(textVtoW, "semihemidemisemihemidemisemihemidemisemiquaver") == string("semihemidemisemihemidemisemihemidemisemiquawer"));
    /*5*/ CHECK(find(textVtoW, "volvo") == string("wolwo"));
    /*6*/ CHECK(find(textVtoW, "viwi") == string("wiwi"));
    /*7*/ CHECK(find(textVtoW, "vife") == string("wife"));
    /*8*/ CHECK(find(textWtoV, "w") == string("v"));
    /*9*/ CHECK(find(textWtoV, "wolwo") == string("volvo"));
    /*10*/ CHECK(find(textWtoV, "semihemidemisemihemidemisemihemidemisemiquawer") == string("semihemidemisemihemidemisemihemidemisemiquaver"));
    /*11*/ CHECK(find(textWtoV, "viwisectionists") == string("vivisectionists"));
    /*12*/ CHECK(find(textWtoV, "vwvw") == string("wvwv"));
    /*13*/ CHECK(find(textWtoV, "wiwi") == string("viwi"));
    /*14*/ CHECK(find(textWtoV, "wwwwv") == string("vvvvw"));
    /*15*/CHECK(find(textWtoV, "valid") == string("walid"));
}

TEST_CASE("Test replacement of b and f and p ")
{
    string text1 = " b papaf pafor baba build boaerp praper";
    string text2="p fix falafal";
    /*1*/ CHECK(find(text1, "f") == string("b"));
    /*2*/ CHECK(find(text1, "p") == string("b"));
    /*3*/ CHECK(find(text1, "bafap") == string("papaf"));
    /*4*/ CHECK(find(text1, "bafor") == string("pafor"));
    /*5*/ CHECK(find(text1, "papa") == string("baba"));
    /*6*/ CHECK(find(text1, "fuild") == string("build"));
    /*7*/ CHECK(find(text1, "poaerp") == string("boaerp"));
    /*8*/ CHECK(find(text1, "praber") == string("praper"));
    /*9*/ CHECK(find(text1, "brafer") == string("praper"));
    /*10*/ CHECK(find(text2, "b") == string("p"));
    /*11*/ CHECK(find(text2, "f") == string("p"));
    /*12*/ CHECK(find(text2, "bix") == string("fix"));
    /*13*/ CHECK(find(text2, "pix") == string("fix"));
    /*14*/ CHECK(find(text2, "falabal") == string("falafal"));
    /*15*/CHECK(find(text2, "palabal") == string("falafal"));
}

TEST_CASE("Test replacement of g and j")
{
    string text1 = "j jojo julian jataim jusdtin job jurdgain ";
    string text2="g glida gligggggda";
    /*1*/ CHECK(find(text1, "g") == string("j"));
    /*2*/ CHECK(find(text1, "gojo") == string("jojo"));
    /*3*/ CHECK(find(text1, "jogo") == string("jojo"));
    /*4*/ CHECK(find(text1, "gogo") == string("jojo"));
    /*5*/ CHECK(find(text1, "gulian") == string("julian"));
    /*6*/ CHECK(find(text1, "gataim") == string("jataim"));
    /*7*/ CHECK(find(text1, "Jusdtin") == string("jusdtin"));
    /*8*/ CHECK(find(text1, "gob") == string("job"));
    /*9*/ CHECK(find(text1, "gurdjain") == string("jurdgain"));
    /*10*/ CHECK(find(text2, "j") == string("g"));
    /*11*/ CHECK(find(text2, "jlida") == string("glida"));
    /*12*/ CHECK(find(text2, "gliggjggda") == string("gligggggda"));
    /*13*/ CHECK(find(text2, "glijggggda") == string("gligggggda"));
    /*14*/ CHECK(find(text2, "gliggggjda") == string("gligggggda"));
    /*15*/CHECK(find(text2, "jligggjgda") == string("gligggggda"));
}

TEST_CASE("Test replacement of c and k and q")
{
    string text1 = "q quiz qck kcq kaka karaqov kapra";
    string text2="k kookoo klita kokoriko";
    /*1*/ CHECK(find(text1, "c") == string("q"));
    /*2*/ CHECK(find(text1, "k") == string("q"));
    /*3*/ CHECK(find(text1, "ckq") == string("qck"));
    /*4*/ CHECK(find(text1, "cqk") == string("qck"));
    /*5*/ CHECK(find(text1, "qaca") == string("kaka"));
    /*6*/ CHECK(find(text1, "caqa") == string("kaka"));
    /*7*/ CHECK(find(text1, "karacov") == string("karaqov"));
    /*8*/ CHECK(find(text1, "carakov") == string("karaqov"));
    /*9*/ CHECK(find(text1, "capra") == string("kapra"));
    /*10*/ CHECK(find(text2, "q") == string("k"));
    /*11*/ CHECK(find(text2, "c") == string("k"));
    /*12*/ CHECK(find(text2, "kooqoo") == string("kookoo"));
    /*13*/ CHECK(find(text2, "qlita") == string("klita"));
    /*14*/ CHECK(find(text2, "coqoriko") == string("kokoriko"));
    /*15*/CHECK(find(text2, "koocoo") == string("kookoo"));
}


TEST_CASE("Test replacement of s and z")
{
    string text1 = "s soso source seazone szszs";
    string text2="z zozoulsz zoransd";
    /*1*/ CHECK(find(text1, "z") == string("s"));
    /*2*/ CHECK(find(text1, "zozo") == string("soso"));
    /*3*/ CHECK(find(text1, "zoso") == string("soso"));
    /*4*/ CHECK(find(text1, "sozo") == string("soso"));
    /*5*/ CHECK(find(text1, "zource") == string("source"));
    /*6*/ CHECK(find(text1, "zeazone") == string("seazone"));
    /*7*/ CHECK(find(text1, "seasone") == string("seazone"));
    /*8*/ CHECK(find(text1, "zeasone") == string("seazone"));
    /*9*/ CHECK(find(text1, "zszsz") == string("szszs"));
    /*10*/ CHECK(find(text2, "s") == string("z"));
    /*11*/ CHECK(find(text2, "sosoulss") == string("zozoulsz"));
    /*12*/ CHECK(find(text2, "zosoulsz") == string("zozoulsz"));
    /*13*/ CHECK(find(text2, "zozoulzs") == string("zozoulsz"));
    /*14*/ CHECK(find(text2, "zoranzd") == string("zoransd"));
    /*15*/CHECK(find(text2, "soransd") == string("zoransd"));
}


TEST_CASE("Test replacement of d and t")
{
    string text1 = "d daridodo doramita datat diti";
    string text2="t toto torlidotl tortalini";
    /*1*/ CHECK(find(text1, "t") == string("d"));
    /*2*/ CHECK(find(text1, "daritodo") == string("daridodo"));
    /*3*/ CHECK(find(text1, "taridoto") == string("daridodo"));
    /*4*/ CHECK(find(text1, "toramida") == string("doramita"));
    /*5*/ CHECK(find(text1, "toramida") == string("doramita"));
    /*6*/ CHECK(find(text1, "tadad") == string("datat"));
    /*7*/ CHECK(find(text1, "tatad") == string("datat"));
    /*8*/ CHECK(find(text1, "dadat") == string("datat"));
    /*9*/ CHECK(find(text1, "didi") == string("diti"));
    /*10*/ CHECK(find(text2, "d") == string("t"));
    /*11*/ CHECK(find(text2, "dodo") == string("toto"));
    /*12*/ CHECK(find(text2, "todo") == string("toto"));
    /*13*/ CHECK(find(text2, "dorlitodl") == string("torlidotl"));
    /*14*/ CHECK(find(text2, "tordalini") == string("tortalini"));
    /*15*/CHECK(find(text2, "dortalini") == string("tortalini"));
}


TEST_CASE("Test replacement of o and u")
{
    string text1 = "o uouo you uoooouuuo ";
    string text2="u olive hoolugdou ";
    /*1*/ CHECK(find(text1, "u") == string("o"));
    /*2*/ CHECK(find(text1, "oouo") == string("uouo"));
    /*3*/ CHECK(find(text1, "oooo") == string("uouo"));
    /*4*/ CHECK(find(text1, "uuuu") == string("uouo"));
    /*5*/ CHECK(find(text1, "ouou") == string("uouo"));
    /*6*/ CHECK(find(text1, "yuu") == string("you"));
    /*7*/ CHECK(find(text1, "yoo") == string("you"));
    /*8*/ CHECK(find(text1, "yuo") == string("you"));
    /*9*/ CHECK(find(text1, "UOUO") == string("uouo"));
    /*10*/ CHECK(find(text2, "o") == string("u"));
    /*11*/ CHECK(find(text2, "hoolugdoo") == string("hoolugdou"));
    /*12*/ CHECK(find(text2, "ulive") == string("olive"));
    /*13*/ CHECK(find(text2, "huolugdou") == string("hoolugdou"));
    /*14*/ CHECK(find(text2, "houlugduu") == string("hoolugdou"));
    /*15*/CHECK(find(text2, "huulogduo") == string("hoolugdou"));
}


TEST_CASE("Test replacement of i and y")
{
    string text1 = "y yiyi yiiiiyiiiy yair yotem yoaiv  ";
    string text2="i iyutei";
    /*1*/ CHECK(find(text1, "i") == string("y"));
    /*2*/ CHECK(find(text1, "iyiy") == string("yiyi"));
    /*3*/ CHECK(find(text1, "yiii") == string("yiyi"));
    /*4*/ CHECK(find(text1, "iiii") == string("yiyi"));
    /*5*/ CHECK(find(text1, "yiiyyyiiiy") == string("yiiiiyiiiy"));
    /*6*/ CHECK(find(text1, "yyiiyyiiiy") == string("yiiiiyiiiy"));
    /*7*/ CHECK(find(text1, "iayr") == string("yair"));
    /*8*/ CHECK(find(text1, "iotem") == string("yotem"));
    /*9*/ CHECK(find(text1, "yoayv") == string("yoaiv"));
    /*10*/ CHECK(find(text2, "y") == string("i"));
    /*11*/ CHECK(find(text2, "iiutei") == string("iyutei"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy semihemidemisemihemiDemisemihemidemisemiquawer yiiIIiyiIiy you daridodo";
    /*1*/ CHECK(find(text, "happi") == string("Happi"));
    /*2*/ CHECK(find(text, "Happi") == string("Happi"));
    /*3*/ CHECK(find(text, "HAPPI") == string("Happi"));
    /*4*/  CHECK(find(text, "HaPpI") == string("Happi"));
    /*5*/  CHECK(find(text, "semihemidemisemihemidemisemihemidemisemiquawer") == string("semihemidemisemihemiDemisemihemidemisemiquawer"));
    /*6*/ CHECK(find(text, "yiiiiiyiIiy") == string("yiiIIiyiIiy"));
    /*7*/ CHECK(find(text, "YiiIIiYiIiy") == string("yiiIIiyiIiy"));
    /*8*/  CHECK(find(text, "YOU") == string("you"));
    /*9*/ CHECK(find(text, "Daridodo") == string("daridodo"));
    /*10*/ CHECK(find(text, "darIdodo") == string("daridodo"));
    /*11*/  CHECK(find(text, "semihemidemisemihemiDemiZemihemYdemisemYquawer") == string("semihemidemisemihemiDemisemihemidemisemiquawer"));
    /*12*/ CHECK(find(text, "XXX") == string("xxx"));
    /*13*/ CHECK(find(text, "xXx") == string("xxx"));
    /*14*/  CHECK(find(text, "IiI") == string("yyy"));
    /*15*/  CHECK(find(text, "yIy") == string("yyy"));

}


