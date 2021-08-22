/**
 * \file unitTest.cpp
 *
 * \author Jordan Hybki (@jh9587)
 * 
 * Unit Testing code to determine versatility and correctness of emgToolbox class for low(11), medium(251) and high(501) amount of datapoints in EMG singal.
 * Checks each function in class for expected value from matlab.
 */

#include <gtest/gtest.h>
#include "../source/emgToolbox.h"

// 251 datapoints
double X0[251] = {0.0126028184348814,0.00454520776248943,0.0110043151049481,0.00267095911947809,-0.00524158181679216,0.0134978029371346,0.0123285893913274,0.0165400112969873,0.00155045464169026,0.00194884932347646,0.00509249176406693,-5.70969184957559e-05,0.0369135425341380,0.0137153352128525,0.00346873675545291,0.0142432290527496,0.0222952826424725,0.0167759678656767,0.0191664964499449,0.0148074548240685,-0.00507144899100580,0.00240106679256384,0.0205984277286783,0.00801915050403180,0.0125920146194335,0.0155492450512301,-0.000214216765194457,0.0119011278993806,0.00565211661474729,-0.00474166655890070,0.0139323296925467,0.00155918797945018,0.00497165555644194,-0.00339219847269793,0.00397036314600464,0.0143953242452541,0.0257150626814332,-0.00131548691416328,0.0134531866633769,0.0152338767757166,0.0204396400912136,0.0225986906219460,-0.00105879506889812,0.0106137314657714,0.0223069368609986,0.0154510573196156,0.0239997595273608,0.0221648831942432,0.0334379960327461,-0.0162002326080676,0.00668149437745067,0.00661366472081013,-0.00423622806365839,0.00478763284229532,0.0242223320421318,0.0105929346320320,0.0196058523057172,0.0263490722032405,0.00709731004202593,0.00590382628554444,-0.00317119646975727,0.00722703235644018,0.00285307277396522,0.00780714567026874,0.00774416883153805,0.00271635996888923,-0.00144682787033701,0.00622312688197506,0.0101462590349818,0.00104328725190157,0.0135223937459084,0.00855871992530961,0.00739343605551120,0.0191173328995951,0.0330618242015673,0.0184764343762861,0.0164269086947992,0.0100472004464365,0.0112978651215934,0.0158142927241028,0.00447019717021839,-0.00492558795155321,0.0142911185712260,0.00298133750013824,0.0139371699200445,0.00169457735088907,-0.00253417173336777,-0.00403430117226221,0.0128110146188365,0.0295453920046404,0.0120043804637693,0.0149050351854076,0.0114380903424203,0.0123009588569895,0.0336547508923074,0.00218731785579572,0.00841110726686744,0.00326290647600352,0.0171404819381030,0.0125518923678767,0.00672737712669883,0.0174210709381367,-5.70393532845759e-05,0.0111942067727222,0.0120044175628734,0.0257385123860363,0.0153862757746210,0.0103306070700226,-0.00341746080322060,-0.00470908406934728,0.0159063095137358,0.00299816380826258,0.00758809288784172,0.00130583031594183,0.0118160318122483,0.0122787984441007,0.0274471993350627,0.0281787413004095,0.0206163290459646,0.0208398538559699,-0.00169672009135466,0.0227577346884409,0.000584276020211784,-0.00599450415628577,0.0416625311280659,0.0131866731206772,0.00337063324148923,0.0100792589456022,0.0106900941910027,-0.0107002803258523,0.00284449935947199,0.0152931945336738,0.0103554031115133,-0.00662894856447335,0.00508507670117053,0.00849933121306011,0.0108133234660466,-0.00678776971289067,0.0125533608712195,0.0252905134358035,-0.00592726602262531,0.0143879028982054,0.0234365141705886,0.0138034770828384,0.0158906425483470,0.00524961791818734,0.00814810965311183,-0.00144715423503240,0.00878493938537165,0.00447382024165476,0.00341967224374906,0.0244725099802365,0.00882942635372761,0.0162993479002457,0.0137530719610252,-0.000148873356927213,-0.00889858215986208,-0.00433756492057559,0.0127594102271539,0.00698791974635752,0.0175950290888421,0.00620052515116551,-0.00322302930480471,0.0109633157710430,0.0210104791591114,0.0126541883215637,0.00814044640747371,0.00579066835773276,0.0226812211435784,0.0191430715644774,0.00570348544488869,-0.00346393843147969,0.000864496362178368,0.0133332669415721,-0.000925887664108063,0.00613048891675345,0.00877564822319430,0.00340222477384089,0.00375522560896386,0.00773687517442288,0.00449159046347665,-0.00342265082414859,0.0173658924841476,0.000804511259807577,0.0203503929497922,0.00656592629592669,0.00692117142356931,0.0229557082560223,0.0126108855728179,0.00597727598482022,0.00173044353194976,0.00482782922834006,0.0139990936694640,0.0184713423311787,0.0104801095670228,0.00507076924524298,0.0133543707517962,0.0167121444865115,0.00578337647709999,0.0244312650276216,0.00635719008727585,0.0189828815063947,0.0196834382813067,0.0105662742636036,0.00915333534082318,0.0187201041102415,-0.00803655327260582,0.0103374007683631,0.0106913860951329,0.0136558677860702,0.00115140305048790,-0.00410175366025607,-0.0163837960560119,0.0154510168334396,0.0207800634320016,0.00555669638782758,0.0337932697796306,0.00359024581639291,-0.00311281589368083,0.00854311938903101,0.0110578503589778,0.0168235229772266,0.0112103979836438,0.00236378852858337,-0.00523023071692662,0.00413307067982608,-0.00363743944741949,0.0172359479144432,0.00896372422866480,-0.00853005818232236,0.0136559467480580,0.000775918931612417,0.0235037753365345,0.0105219786667248,0.0122923326883344,0.00212620663342855,0.0152301640303770,0.0106490303883348,0.0121616713206400,0.00679726607406829,0.0164338000276206,-0.0143920614159571,0.0116568034785705,0.0204820655515325,0.00809333354371705,0.0157813357919509,0.00404504742794447,0.0117274821745615,0.00416023093989032,0.0214502586032493,0.0146994283562637};
// 501 datapoints
double X1[501] = {0.00217913509690807,0.0142578916067829,0.0201154049577290,0.00749332632398550,0.0155423606472887,0.0175888079577618,0.0113384265966310,0.00727438503534674,0.00457372347951350,-0.00163104552171043,0.00726482604760530,0.0115950387496610,0.00813291877396758,0.0121790414667227,0.0104623830018616,0.0167032496636249,0.00369499056698869,0.00881589841816952,0.0124206458388560,0.00623915374824928,0.0128044440670892,-0.00774452142192791,0.0145857781469230,0.0146182288955257,0.00998812513448019,0.00647061246102169,0.00567008744270376,-0.00704774103824856,0.0209571673703715,0.0163577211576334,-0.000871843175504930,-0.00477265430330513,0.00614750585265038,0.0168083665756682,0.0183264934868829,0.0153459823662248,0.0176802456911770,0.0275488767050520,-0.00704312441131250,0.0146950822427503,0.00945696155007059,0.00251125018488742,0.0171676404170375,0.00994487098582957,0.0220011431909571,-0.000340171388805599,0.00152432245533832,0.0143342203687297,0.00112476020574244,0.0112123262080276,0.00598095109517255,0.0209667832321064,0.0143667464821827,0.00592995309570805,0.00361309832995376,0.00595118800095664,0.0339386245648773,0.00950376986354226,0.00797424091633106,0.00802465949060265,0.0251631602653726,-0.00732208108756652,0.0211247251331936,0.00280718973268230,0.00726634421500652,0.0167740441918668,0.000635491785954635,0.0142571685055678,0.00925456896616502,-0.00398807286855987,0.0119230610415782,0.0158038971590549,0.0163785926380368,0.00434018375574504,0.00983862373683189,0.0162232256533520,0.0153343636175516,0.00610659244364464,-0.00271667788211018,0.0127260106164183,0.0131746846488797,0.0249836827592653,-0.00553800791149888,0.00645708377057886,0.0143422762215240,0.00898521979595947,0.0302876798537404,0.00632788121617720,-0.0136377484799189,0.0172985834536179,-0.00399020759278394,0.0231488703713417,0.0140382537467252,0.00655833772236960,0.000199357426967265,0.0285734541988710,0.0130953845261044,0.00510897273974102,0.00305116701970141,0.00819607398383320,0.0225628334419483,0.0291074361906141,0.0102719296096157,0.0142712943590941,0.0132336483607031,-0.00648968034028329,0.0114033798747639,0.00501957262435517,0.00572226974990156,0.00849125657017932,-0.0189081005793843,0.00265457939139748,0.0175621521677762,0.0112079284251505,0.00484094353350172,0.00659141580860584,-0.000799921513580169,0.00302611088006539,0.00417003287345296,0.00813874586537475,0.0158796061832631,0.00978958602990006,0.00920238691667414,0.00164485214456942,0.0197862007759062,0.0123547791161079,0.0156604774170135,0.0121929025370224,0.0180771101277303,0.0251252674055338,0.00568366577440323,0.0154256058104182,0.0167929989241518,0.00991233088994771,0.0291194131724684,0.000213841453094806,0.00513870797249258,0.0107789795155420,0.0102620100311479,0.00777216126216634,0.00520294500815679,0.0182458731396565,0.00939596673333937,0.00193236169865554,0.0271283780149174,0.0191215835116302,0.0248884170716556,0.00973251950976039,0.0291582423437216,0.0191967710842216,-0.00808098686700256,-0.00265307850420281,0.0158363061550354,0.00883812041513655,0.00856187731392702,0.0207476955634590,0.0270218903333732,0.0139123533640833,0.0112733157271726,0.0325093102373581,0.00989322068765205,0.00549450817640463,0.00404950421071497,0.00264330416471178,0.0108169506186916,0.00139143037045941,-0.00858410481485350,-0.00284886889862722,0.0143620216564384,0.0209128280274507,0.0220260219158596,0.0331286363180140,-0.000839793468450334,0.0236453423431839,0.0108168022254119,0.00532217773916436,0.00573620323926378,0.0188962463504309,0.0164975002331503,-0.00806178600415164,0.0202469639873353,0.0182523226367464,0.00763667735122874,0.000187341327199084,0.00230411767706741,-0.00236122875485133,0.00949785293366272,0.00611335997826516,0.00688054889028957,0.0122136469959572,0.00702675014940351,-0.00697194726045443,0.00401290709702631,0.00476653188336780,-0.00715828844521470,0.0188567785614735,-0.0116664537207453,0.0142212688051616,0.00705190903171323,0.00635748673090995,0.0164765601097298,0.00696467791542172,0.00773162066906836,0.00128419165747715,0.0212575950072613,0.0199161878882813,0.0168643725422197,0.0153125429207575,0.0172643704244358,0.0169425386430659,0.0139410062061747,0.0163162413596695,0.00290896610207146,0.0102934666042106,0.0155037690789583,0.00274517369593303,0.0100076437211187,0.00812488686737405,0.0224142423653386,0.0147248829125317,0.0209447241004039,0.0162267009049154,0.0200923380981389,0.00905502765962098,0.0111515280854568,0.00371843009687282,0.0138757246477054,0.0407427285791099,0.0109758636157010,0.00954405360878116,0.0185825567660560,-0.00563618748822747,0.0212822835447902,0.00152428293993603,0.0156750716241983,0.0127659692106440,0.00932974758023459,0.00282721768160612,0.0141731171998116,0.0212455990837310,0.0168264324064136,0.0239609165386057,-0.00388589150158688,0.0101926248072772,-0.00350353480441838,0.0111463550104281,0.0154163175423328,0.00232334136759264,0.0228282508097244,0.00525143621836635,0.0162343104639320,0.00652302631937216,0.00241675880978341,0.00262834878240669,-0.00451035761870434,0.0252075373827983,-0.0144723723140752,-0.00290046407135652,-0.00984573790123961,-0.00342946814114655,-0.0179183867725625,0.0160218634030997,0.0104044270457392,-0.000309176735814911,-0.00300975583777577,-0.00317979033557504,0.00721544560363677,-0.0102209299100739,0.0140672984270458,0.00910173948622959,0.00657737579381928,0.0165222576962773,0.0134574487869943,0.00655314309786321,0.0103078594622858,0.00866652144613405,0.00373962652148663,0.0211143973329332,0.0220216625919678,0.0107238185681210,-0.000267475714006169,-0.00172970487707480,0.0125100421714000,0.00735377790802941,0.00186809226060486,0.0113201678296148,-0.00184651694947953,0.0134042055432280,-0.00592093418091683,-0.0145376333567772,0.00791879421995508,0.000180701157533216,0.0253111911748754,0.0237266970096743,0.00387882093138126,0.000332629774536946,0.00783604600599156,0.00683917538267944,0.0238531742796890,0.00651704675264635,0.0220551098077773,0.0223724348270003,0.0351972353887408,0.00620549864536053,0.00524731459139992,0.0267572534732786,0.00261630997954340,-0.00815502969921097,0.0108672831708135,0.0150025750546134,0.00637019169747360,0.00649307951791424,-0.00362909929145892,0.0272280393053936,0.0120137215132507,0.00452313207818609,0.0140181236392557,0.0183439500879587,-0.000482967118777682,0.0122526321008823,0.00517630270435064,0.0265071534952283,0.0115892575079893,-0.00124685380767514,0.00888936523248169,0.0144905097875768,0.0310058337565659,0.0103956746808077,0.0157157258110114,0.0220072615149522,0.0150877197186977,0.00130238289261873,0.00838935445719027,0.00342175053736589,0.0170675183542371,0.0254031716106385,0.00978058353563682,0.0205476174337987,0.00303242177765517,0.0115930138999625,0.00823529864807517,0.0263025921041222,0.0129396392302699,0.0176771316612544,0.00658813393372647,0.00366597359779413,0.0139470297405088,0.00181561403463866,-0.00361729682961699,0.00697882605959499,0.0259917448056000,0.00607678895889739,0.0122082844092680,0.00406278137592237,-0.0105039292357894,0.0100042709295680,0.0269365989635426,0.00668471696330386,-0.00150144562140766,9.32777575575139e-05,0.0136418987361591,0.00579668705507913,0.0198362168541954,0.00724234822131549,-0.0108552388544554,0.00560528736198871,0.0171192447178031,0.0202647611247127,0.0228493457593153,0.0200072030940208,0.0207339134627375,0.0289403249947036,0.0253443238038807,0.0117558857286772,0.00523882229456898,0.00720251399727853,0.0170263035473701,0.0220817483441273,0.00752440696054303,0.0251267048749378,0.00275052868674801,0.00534668871175495,0.00613049123411131,0.00338049603787867,0.0186990128763014,0.00812914097020553,0.0285153725956133,0.00993871473668597,0.0286628025483063,-0.0142996842750187,0.0136181676324200,0.0128348347922447,0.0293518896339976,0.0126172399750755,0.0277916155128747,0.0289273585111754,0.00379684228498468,-0.00190656649158769,0.0185819401339825,0.00184923006447062,0.00842846805901431,0.00428771218065560,0.0110081065657188,0.0159642491900723,0.0171220375830268,0.0113564133138132,0.000530913498529191,0.00153072287865188,0.0129230275835577,-0.0118430098739831,-0.00174444681941604,-0.00565768793095184,0.00672053239792766,0.0148522131432710,0.0336475023131983,0.00995873003148198,-0.000676382647072138,0.00546451187212676,0.0145822126552696,0.0202184682466807,0.00540925226618443,0.00995390151468038,0.0218586171245979,0.0122373938508100,0.0108039214645664,0.00668932432388742,0.00615371815186459,0.0205800356400635,0.00468340496560527,0.00952729516370041,-0.000338193422561852,0.0160374541293122,0.0124917612930269,0.0144154375928635,0.00973073800502501,0.00257901680150358,0.00914685034308713,-0.00284109016934457,0.00661404269978691,0.0330718974037581,0.0267231314356343,0.0186777559397268,0.0143806436112611,0.0182655535855394,0.0138950077096391,0.0193175017661401,0.0220576304887843,-0.000212577461647103,0.00809010579752159,0.00972849163058736,0.00444881097032356,5.81641126299015e-05,0.0227212028110039,0.0166781334150072,0.000892239839216457,-0.000526780309903388,0.0142719929343086,0.00311161660997969,-0.00198299229274990,0.00752542047874737,0.00155266288038956,0.0184961730267880,0.0330657297317478,-0.00700952704712513,0.0183750284512080,0.0142243249467860,0.00157444482294732,0.0196165795722333,0.00111625297707532,-0.00882249697157461,-0.00123314259588418,0.0157816334067523,0.0141031022582830,0.0200265489986213,0.0149077304854858,0.0226035451841525,-0.0100481319036761,0.00695494882139218,0.00636796334165137,0.00942115601550803,0.0206718342047092,0.00323575762327346,0.0125245355070692,-0.00910667190785244,0.000846430809999528,0.0194014494226622,-0.00743463991708477,0.0241484583281253,0.00515897745347085,0.0152776728734667,-0.00176278061136629,0.0175480866741142,0.00998589451266737,0.0225406120773463,0.00453255566323373,0.00264644958791546,0.00243922143595550,0.0297470748729788,0.00670288575002378,-0.00609012851018651,0.0194856719177502};
// 11 datapoints
double X2[11] = {-0.00157442000509990,0.00238013640215166,0.00749700412825595,-0.00648763085360877,0.00818009382730489,0.0161568722972018,0.00623325729132609,0.00301964730413982,0.0130412243003020,0.0210107991908192,0.00553392028962171};

// Matlab results that are accepted values.
double R0[40] = {0.0579701373845995,22.3164784142597,0.0105504181301204,0.000185156505528483,0.00000000000000,1.00324314083260,0.0105926198026409,0.0132714106509408,0.000176837691431631,0.0596613189557124,14.4566982039168,2.79926651740759,0.012188110357436,3.32178589590091,0.00323789319419329,0.00790597328300533,-4.55158978665867,-4.32214313252443,-3.72594191240965,-0.678112908115377,0.00761027661554757,0.0111524562446517,0.0889102725667719,0.00828427822978085,0.00557137336878393,0.231075697211155,14.0000000000000,0.0136072225501196,0.0464742828876492,0.182156192966858,120.000000000000,0.00964696827602933,3.72562144623330e-06,9.30639969187162e-05,0.000185897131550597,0.0136072225501196,2.64815495066023,115.000000000000,47.0000000000000};
double R1[40] = {0.0608258335582974,46.0137752774500,0.0108677381071062,0.000200104003459353,0.00000000000000,0.972757575433745,0.0108894735833205,0.0136684498983958,0.000187200924473904,0.0602948346219282,28.8549643371875,5.86792999372961,0.012961663230136,2.98511295879538,-0.0276203795006680,0.00828617712974041,-4.52195668532467,-4.29266502908734,-3.05880423872254,-0.514795732623683,0.00783555569893743,0.0117124351172248,0.0918438628292415,0.00884962727165611,0.00584288708685226,0.277445109780439,2.00000000000000,0.0141458122233880,0.100252105733136,-0.000317798773312729,244.000000000000,0.00986831979762318,4.00159865853776e-06,9.73837356281615e-05,0.000200504211466271,0.0141458122233880,5.44473679166023,226.000000000000,92.0000000000000};
double R2[40] = {0.0512647706687952,0.829129936641983,0.00839143800427000,0.000102229089459051,0.00000000000000,1.14871853503283,0.00923058180469700,0.0101412392893372,0.000114271927026217,0.0525386895972112,0.550247555585123,0.0911150058898318,0.01066108789815,2.53248953548776,0.138647003699209,0.00635899991872986,-4.78054337816325,-4.59114507040375,-7.07561180831453,-1.49390896969366,0.00578167620364711,0.00828318235362107,0.0753754487856348,0.00630406870871223,0.00297756481646389,0.181818181818182,0.00000000000000,0.0101108401955056,0.00112451998404956,0.180645231254788,4.00000000000000,0.00783122196197486,1.53230613561943e-06,6.13280374177174e-05,0.000112451998404956,0.0101108401955056,0.0923058180469700,4.00000000000000,2.00000000000000};


// Demonstrate some basic assertions.
// Checks each function in class for expected value from matlab.
TEST(emgToolbox, AbsoluteValueOfTheSummationOfExpRoot) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[0], emgFunctions1.ASM(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[0], emgFunctions2.ASM(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[0], emgFunctions3.ASM(), 0.000001f);
}

TEST(emgToolbox, AbsoluteValueOfTheSummationOfSquareRoot) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[1], emgFunctions1.ASS(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[1], emgFunctions2.ASS(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[1], emgFunctions3.ASS(), 0.000001f);
}

TEST(emgToolbox, AverageAmplitudeChange) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[2], emgFunctions1.AAC(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[2], emgFunctions2.AAC(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[2], emgFunctions3.AAC(), 0.000001f);
}

TEST(emgToolbox, AverageEnergy) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[3], emgFunctions1.ME(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[3], emgFunctions2.ME(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[3], emgFunctions3.ME(), 0.000001f);
}

TEST(emgToolbox, Cardinality) 
{
    emgToolbox emgFunctions1(X0, 251, 0.01);
    EXPECT_NEAR(R0[4], emgFunctions1.CARD(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0.01);
    EXPECT_NEAR(R1[4], emgFunctions2.CARD(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0.01);
    EXPECT_NEAR(R2[4], emgFunctions3.CARD(), 0.000001f);
}
TEST(emgToolbox, CoefficientOfVariation) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[5], emgFunctions1.COV(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[5], emgFunctions2.COV(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[5], emgFunctions3.COV(), 0.000001f);
}

TEST(emgToolbox, DifferenceAbsoluteMeanValue) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[6], emgFunctions1.DAMV(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[6], emgFunctions2.DAMV(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[6], emgFunctions3.DAMV(), 0.000001f);
}

TEST(emgToolbox, DifferenceAbsoluteStandardDeviationValue) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[7], emgFunctions1.DASDV(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[7], emgFunctions2.DASDV(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[7], emgFunctions3.DASDV(), 0.000001f);
}

TEST(emgToolbox, DifferenceVarianceValue) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[8], emgFunctions1.DVARV(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[8], emgFunctions2.DVARV(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[8], emgFunctions3.DVARV(), 0.000001f);
}

TEST(emgToolbox, EnhancedMeanAbsoluteValue) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[9], emgFunctions1.EMAV(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[9], emgFunctions2.EMAV(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[9], emgFunctions3.EMAV(), 0.000001f);
}

TEST(emgToolbox, EnhancedWaveLength) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[10], emgFunctions1.EWL(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[10], emgFunctions2.EWL(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[10], emgFunctions3.EWL(), 0.000001f);
}

TEST(emgToolbox, IntegratedEMG) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[11], emgFunctions1.IEMG(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[11], emgFunctions2.IEMG(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[11], emgFunctions3.IEMG(), 0.000001f);
}

TEST(emgToolbox, InterquartileRange) 
{
    // No idea how Matlab found their answer, works with Wolfram Alpha.
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[12], emgFunctions1.IQR(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[12], emgFunctions2.IQR(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[12], emgFunctions3.IQR(), 0.000001f);
}

TEST(emgToolbox, Kurtosis) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[13], emgFunctions1.KURT(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[13], emgFunctions2.KURT(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[13], emgFunctions3.KURT(), 0.000001f);
}


TEST(emgToolbox, LogCoefficientOfVariation) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[14], emgFunctions1.LCOV(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[14], emgFunctions2.LCOV(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[14], emgFunctions3.LCOV(), 0.000001f);
}

TEST(emgToolbox, LogDetector) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[15], emgFunctions1.LD(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[15], emgFunctions2.LD(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[15], emgFunctions3.LD(), 0.000001f);
}

TEST(emgToolbox, LogDifferenceAbsoluteMeanValue) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[16], emgFunctions1.LDAMV(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[16], emgFunctions2.LDAMV(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[16], emgFunctions3.LDAMV(), 0.000001f);
}

TEST(emgToolbox, LogDifferenceAbsoluteStandardDeviationValue) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[17], emgFunctions1.LDASDV(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[17], emgFunctions2.LDASDV(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[17], emgFunctions3.LDASDV(), 0.000001f);
}

TEST(emgToolbox, LogTeagerKaiserEnergyOperator) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[18], emgFunctions1.LTKEO(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[18], emgFunctions2.LTKEO(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[18], emgFunctions3.LTKEO(), 0.000001f);
}

TEST(emgToolbox, MaximumFractalLength) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[19], emgFunctions1.MFL(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[19], emgFunctions2.MFL(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[19], emgFunctions3.MFL(), 0.000001f);
}

TEST(emgToolbox, MeanAbsoluteDeviation) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[20], emgFunctions1.MAD(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[20], emgFunctions2.MAD(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[20], emgFunctions3.MAD(), 0.000001f);
}

TEST(emgToolbox, MeanAbsoluteValue) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[21], emgFunctions1.MAV(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[21], emgFunctions2.MAV(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[21], emgFunctions3.MAV(), 0.000001f);
}

TEST(emgToolbox, MeanValueOfTheSquareRoot) 
{
    // Real and imaginary result converted into size for one 
    // valued double result.
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[22], emgFunctions1.MSR(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[22], emgFunctions2.MSR(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[22], emgFunctions3.MSR(), 0.000001f);
}

TEST(emgToolbox, ModifiedMeanAbsoluteValue) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[23], emgFunctions1.MMAV(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[23], emgFunctions2.MMAV(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[23], emgFunctions3.MMAV(), 0.000001f);
}

TEST(emgToolbox, ModifiedMeanAbsoluteValue2) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[24], emgFunctions1.MMAV2(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[24], emgFunctions2.MMAV2(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[24], emgFunctions3.MMAV2(), 0.000001f);
}

TEST(emgToolbox, MyopulsePercentageRate) 
{
    emgToolbox emgFunctions1(X0, 251, 0.016);
    EXPECT_NEAR(R0[25], emgFunctions1.MYOP(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0.016);
    EXPECT_NEAR(R1[25], emgFunctions2.MYOP(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0.016);
    EXPECT_NEAR(R2[25], emgFunctions3.MYOP(), 0.000001f);
}

TEST(emgToolbox, NewZeroCrossing) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[26], emgFunctions1.FZC(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[26], emgFunctions2.FZC(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[26], emgFunctions3.FZC(), 0.000001f);
}

TEST(emgToolbox, RootMeanSquare) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[27], emgFunctions1.RMS(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[27], emgFunctions2.RMS(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[27], emgFunctions3.RMS(), 0.000001f);
}

TEST(emgToolbox, SimpleSquareIntegral) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[28], emgFunctions1.SSI(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[28], emgFunctions2.SSI(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[28], emgFunctions3.SSI(), 0.000001f);
}

TEST(emgToolbox, Skewness) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[29], emgFunctions1.SKEW(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[29], emgFunctions2.SKEW(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[29], emgFunctions3.SKEW(), 0.000001f);
}

TEST(emgToolbox, SlopeSignChange) 
{
    emgToolbox emgFunctions1(X0, 251, 0.01);
    EXPECT_NEAR(R0[30], emgFunctions1.SSC(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0.01);
    EXPECT_NEAR(R1[30], emgFunctions2.SSC(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0.01);
    EXPECT_NEAR(R2[30], emgFunctions3.SSC(), 0.000001f);
}

TEST(emgToolbox, StandardDeviation) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[31], emgFunctions1.SD(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[31], emgFunctions2.SD(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[31], emgFunctions3.SD(), 0.000001f);
}

TEST(emgToolbox, TemporalMoment) 
{
    emgToolbox emgFunctions1(X0, 251, 3);
    EXPECT_NEAR(R0[32], emgFunctions1.TM(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 3);
    EXPECT_NEAR(R1[32], emgFunctions2.TM(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 3);
    EXPECT_NEAR(R2[32], emgFunctions3.TM(), 0.000001f);
}

TEST(emgToolbox, Variance) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[33], emgFunctions1.VAR(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[33], emgFunctions2.VAR(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[33], emgFunctions3.VAR(), 0.000001f);
}

TEST(emgToolbox, VarianceOfEMG) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[34], emgFunctions1.VAREMG(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[34], emgFunctions2.VAREMG(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[34], emgFunctions3.VAREMG(), 0.000001f);
}

TEST(emgToolbox, VOrder) 
{
    emgToolbox emgFunctions1(X0, 251, 2);
    EXPECT_NEAR(R0[35], emgFunctions1.VO(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 2);
    EXPECT_NEAR(R1[35], emgFunctions2.VO(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 2);
    EXPECT_NEAR(R2[35], emgFunctions3.VO(), 0.000001f);
}

TEST(emgToolbox, WaveformLength) 
{
    emgToolbox emgFunctions1(X0, 251, 0);
    EXPECT_NEAR(R0[36], emgFunctions1.WL(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0);
    EXPECT_NEAR(R1[36], emgFunctions2.WL(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0);
    EXPECT_NEAR(R2[36], emgFunctions3.WL(), 0.000001f);
}

TEST(emgToolbox, WillisonAmplitude) 
{
    emgToolbox emgFunctions1(X0, 251, 0.01);
    EXPECT_NEAR(R0[37], emgFunctions1.WA(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0.01);
    EXPECT_NEAR(R1[37], emgFunctions2.WA(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0.01);
    EXPECT_NEAR(R2[37], emgFunctions3.WA(), 0.000001f);
}

TEST(emgToolbox, ZeroCrossing) 
{
    emgToolbox emgFunctions1(X0, 251, 0.01);
    EXPECT_NEAR(R0[38], emgFunctions1.ZC(), 0.000001f);
    emgToolbox emgFunctions2(X1, 501, 0.01);
    EXPECT_NEAR(R1[38], emgFunctions2.ZC(), 0.000001f);
    emgToolbox emgFunctions3(X2, 11, 0.01);
    EXPECT_NEAR(R2[38], emgFunctions3.ZC(), 0.000001f);
}
