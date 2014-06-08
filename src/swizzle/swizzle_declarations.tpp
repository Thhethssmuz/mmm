swizzle<T,n,0> x, r, s;
swizzle<T,n,1> y, g, t;
swizzle<T,n,2> z, b, p;
swizzle<T,n,3> w, a, q;

swizzle<T,n,0,0> xx, rr, ss;
swizzle<T,n,0,1> xy, rg, st;
swizzle<T,n,0,2> xz, rb, sp;
swizzle<T,n,0,3> xw, ra, sq;
swizzle<T,n,1,0> yx, gr, ts;
swizzle<T,n,1,1> yy, gg, tt;
swizzle<T,n,1,2> yz, gb, tp;
swizzle<T,n,1,3> yw, ga, tq;
swizzle<T,n,2,0> zx, br, ps;
swizzle<T,n,2,1> zy, bg, pt;
swizzle<T,n,2,2> zz, bb, pp;
swizzle<T,n,2,3> zw, ba, pq;
swizzle<T,n,3,0> wx, ar, qs;
swizzle<T,n,3,1> wy, ag, qt;
swizzle<T,n,3,2> wz, ab, qp;
swizzle<T,n,3,3> ww, aa, qq;

swizzle<T,n,0,0,0> xxx, rrr, sss;
swizzle<T,n,0,0,1> xxy, rrg, sst;
swizzle<T,n,0,0,2> xxz, rrb, ssp;
swizzle<T,n,0,0,3> xxw, rra, ssq;
swizzle<T,n,0,1,0> xyx, rgr, sts;
swizzle<T,n,0,1,1> xyy, rgg, stt;
swizzle<T,n,0,1,2> xyz, rgb, stp;
swizzle<T,n,0,1,3> xyw, rga, stq;
swizzle<T,n,0,2,0> xzx, rbr, sps;
swizzle<T,n,0,2,1> xzy, rbg, spt;
swizzle<T,n,0,2,2> xzz, rbb, spp;
swizzle<T,n,0,2,3> xzw, rba, spq;
swizzle<T,n,0,3,0> xwx, rar, sqs;
swizzle<T,n,0,3,1> xwy, rag, sqt;
swizzle<T,n,0,3,2> xwz, rab, sqp;
swizzle<T,n,0,3,3> xww, raa, sqq;
swizzle<T,n,1,0,0> yxx, grr, tss;
swizzle<T,n,1,0,1> yxy, grg, tst;
swizzle<T,n,1,0,2> yxz, grb, tsp;
swizzle<T,n,1,0,3> yxw, gra, tsq;
swizzle<T,n,1,1,0> yyx, ggr, tts;
swizzle<T,n,1,1,1> yyy, ggg, ttt;
swizzle<T,n,1,1,2> yyz, ggb, ttp;
swizzle<T,n,1,1,3> yyw, gga, ttq;
swizzle<T,n,1,2,0> yzx, gbr, tps;
swizzle<T,n,1,2,1> yzy, gbg, tpt;
swizzle<T,n,1,2,2> yzz, gbb, tpp;
swizzle<T,n,1,2,3> yzw, gba, tpq;
swizzle<T,n,1,3,0> ywx, gar, tqs;
swizzle<T,n,1,3,1> ywy, gag, tqt;
swizzle<T,n,1,3,2> ywz, gab, tqp;
swizzle<T,n,1,3,3> yww, gaa, tqq;
swizzle<T,n,2,0,0> zxx, brr, pss;
swizzle<T,n,2,0,1> zxy, brg, pst;
swizzle<T,n,2,0,2> zxz, brb, psp;
swizzle<T,n,2,0,3> zxw, bra, psq;
swizzle<T,n,2,1,0> zyx, bgr, pts;
swizzle<T,n,2,1,1> zyy, bgg, ptt;
swizzle<T,n,2,1,2> zyz, bgb, ptp;
swizzle<T,n,2,1,3> zyw, bga, ptq;
swizzle<T,n,2,2,0> zzx, bbr, pps;
swizzle<T,n,2,2,1> zzy, bbg, ppt;
swizzle<T,n,2,2,2> zzz, bbb, ppp;
swizzle<T,n,2,2,3> zzw, bba, ppq;
swizzle<T,n,2,3,0> zwx, bar, pqs;
swizzle<T,n,2,3,1> zwy, bag, pqt;
swizzle<T,n,2,3,2> zwz, bab, pqp;
swizzle<T,n,2,3,3> zww, baa, pqq;
swizzle<T,n,3,0,0> wxx, arr, qss;
swizzle<T,n,3,0,1> wxy, arg, qst;
swizzle<T,n,3,0,2> wxz, arb, qsp;
swizzle<T,n,3,0,3> wxw, ara, qsq;
swizzle<T,n,3,1,0> wyx, agr, qts;
swizzle<T,n,3,1,1> wyy, agg, qtt;
swizzle<T,n,3,1,2> wyz, agb, qtp;
swizzle<T,n,3,1,3> wyw, aga, qtq;
swizzle<T,n,3,2,0> wzx, abr, qps;
swizzle<T,n,3,2,1> wzy, abg, qpt;
swizzle<T,n,3,2,2> wzz, abb, qpp;
swizzle<T,n,3,2,3> wzw, aba, qpq;
swizzle<T,n,3,3,0> wwx, aar, qqs;
swizzle<T,n,3,3,1> wwy, aag, qqt;
swizzle<T,n,3,3,2> wwz, aab, qqp;
swizzle<T,n,3,3,3> www, aaa, qqq;

swizzle<T,n,0,0,0,0> xxxx, rrrr, ssss;
swizzle<T,n,0,0,0,1> xxxy, rrrg, ssst;
swizzle<T,n,0,0,0,2> xxxz, rrrb, sssp;
swizzle<T,n,0,0,0,3> xxxw, rrra, sssq;
swizzle<T,n,0,0,1,0> xxyx, rrgr, ssts;
swizzle<T,n,0,0,1,1> xxyy, rrgg, sstt;
swizzle<T,n,0,0,1,2> xxyz, rrgb, sstp;
swizzle<T,n,0,0,1,3> xxyw, rrga, sstq;
swizzle<T,n,0,0,2,0> xxzx, rrbr, ssps;
swizzle<T,n,0,0,2,1> xxzy, rrbg, sspt;
swizzle<T,n,0,0,2,2> xxzz, rrbb, sspp;
swizzle<T,n,0,0,2,3> xxzw, rrba, sspq;
swizzle<T,n,0,0,3,0> xxwx, rrar, ssqs;
swizzle<T,n,0,0,3,1> xxwy, rrag, ssqt;
swizzle<T,n,0,0,3,2> xxwz, rrab, ssqp;
swizzle<T,n,0,0,3,3> xxww, rraa, ssqq;
swizzle<T,n,0,1,0,0> xyxx, rgrr, stss;
swizzle<T,n,0,1,0,1> xyxy, rgrg, stst;
swizzle<T,n,0,1,0,2> xyxz, rgrb, stsp;
swizzle<T,n,0,1,0,3> xyxw, rgra, stsq;
swizzle<T,n,0,1,1,0> xyyx, rggr, stts;
swizzle<T,n,0,1,1,1> xyyy, rggg, sttt;
swizzle<T,n,0,1,1,2> xyyz, rggb, sttp;
swizzle<T,n,0,1,1,3> xyyw, rgga, sttq;
swizzle<T,n,0,1,2,0> xyzx, rgbr, stps;
swizzle<T,n,0,1,2,1> xyzy, rgbg, stpt;
swizzle<T,n,0,1,2,2> xyzz, rgbb, stpp;
swizzle<T,n,0,1,2,3> xyzw, rgba, stpq;
swizzle<T,n,0,1,3,0> xywx, rgar, stqs;
swizzle<T,n,0,1,3,1> xywy, rgag, stqt;
swizzle<T,n,0,1,3,2> xywz, rgab, stqp;
swizzle<T,n,0,1,3,3> xyww, rgaa, stqq;
swizzle<T,n,0,2,0,0> xzxx, rbrr, spss;
swizzle<T,n,0,2,0,1> xzxy, rbrg, spst;
swizzle<T,n,0,2,0,2> xzxz, rbrb, spsp;
swizzle<T,n,0,2,0,3> xzxw, rbra, spsq;
swizzle<T,n,0,2,1,0> xzyx, rbgr, spts;
swizzle<T,n,0,2,1,1> xzyy, rbgg, sptt;
swizzle<T,n,0,2,1,2> xzyz, rbgb, sptp;
swizzle<T,n,0,2,1,3> xzyw, rbga, sptq;
swizzle<T,n,0,2,2,0> xzzx, rbbr, spps;
swizzle<T,n,0,2,2,1> xzzy, rbbg, sppt;
swizzle<T,n,0,2,2,2> xzzz, rbbb, sppp;
swizzle<T,n,0,2,2,3> xzzw, rbba, sppq;
swizzle<T,n,0,2,3,0> xzwx, rbar, spqs;
swizzle<T,n,0,2,3,1> xzwy, rbag, spqt;
swizzle<T,n,0,2,3,2> xzwz, rbab, spqp;
swizzle<T,n,0,2,3,3> xzww, rbaa, spqq;
swizzle<T,n,0,3,0,0> xwxx, rarr, sqss;
swizzle<T,n,0,3,0,1> xwxy, rarg, sqst;
swizzle<T,n,0,3,0,2> xwxz, rarb, sqsp;
swizzle<T,n,0,3,0,3> xwxw, rara, sqsq;
swizzle<T,n,0,3,1,0> xwyx, ragr, sqts;
swizzle<T,n,0,3,1,1> xwyy, ragg, sqtt;
swizzle<T,n,0,3,1,2> xwyz, ragb, sqtp;
swizzle<T,n,0,3,1,3> xwyw, raga, sqtq;
swizzle<T,n,0,3,2,0> xwzx, rabr, sqps;
swizzle<T,n,0,3,2,1> xwzy, rabg, sqpt;
swizzle<T,n,0,3,2,2> xwzz, rabb, sqpp;
swizzle<T,n,0,3,2,3> xwzw, raba, sqpq;
swizzle<T,n,0,3,3,0> xwwx, raar, sqqs;
swizzle<T,n,0,3,3,1> xwwy, raag, sqqt;
swizzle<T,n,0,3,3,2> xwwz, raab, sqqp;
swizzle<T,n,0,3,3,3> xwww, raaa, sqqq;
swizzle<T,n,1,0,0,0> yxxx, grrr, tsss;
swizzle<T,n,1,0,0,1> yxxy, grrg, tsst;
swizzle<T,n,1,0,0,2> yxxz, grrb, tssp;
swizzle<T,n,1,0,0,3> yxxw, grra, tssq;
swizzle<T,n,1,0,1,0> yxyx, grgr, tsts;
swizzle<T,n,1,0,1,1> yxyy, grgg, tstt;
swizzle<T,n,1,0,1,2> yxyz, grgb, tstp;
swizzle<T,n,1,0,1,3> yxyw, grga, tstq;
swizzle<T,n,1,0,2,0> yxzx, grbr, tsps;
swizzle<T,n,1,0,2,1> yxzy, grbg, tspt;
swizzle<T,n,1,0,2,2> yxzz, grbb, tspp;
swizzle<T,n,1,0,2,3> yxzw, grba, tspq;
swizzle<T,n,1,0,3,0> yxwx, grar, tsqs;
swizzle<T,n,1,0,3,1> yxwy, grag, tsqt;
swizzle<T,n,1,0,3,2> yxwz, grab, tsqp;
swizzle<T,n,1,0,3,3> yxww, graa, tsqq;
swizzle<T,n,1,1,0,0> yyxx, ggrr, ttss;
swizzle<T,n,1,1,0,1> yyxy, ggrg, ttst;
swizzle<T,n,1,1,0,2> yyxz, ggrb, ttsp;
swizzle<T,n,1,1,0,3> yyxw, ggra, ttsq;
swizzle<T,n,1,1,1,0> yyyx, gggr, ttts;
swizzle<T,n,1,1,1,1> yyyy, gggg, tttt;
swizzle<T,n,1,1,1,2> yyyz, gggb, tttp;
swizzle<T,n,1,1,1,3> yyyw, ggga, tttq;
swizzle<T,n,1,1,2,0> yyzx, ggbr, ttps;
swizzle<T,n,1,1,2,1> yyzy, ggbg, ttpt;
swizzle<T,n,1,1,2,2> yyzz, ggbb, ttpp;
swizzle<T,n,1,1,2,3> yyzw, ggba, ttpq;
swizzle<T,n,1,1,3,0> yywx, ggar, ttqs;
swizzle<T,n,1,1,3,1> yywy, ggag, ttqt;
swizzle<T,n,1,1,3,2> yywz, ggab, ttqp;
swizzle<T,n,1,1,3,3> yyww, ggaa, ttqq;
swizzle<T,n,1,2,0,0> yzxx, gbrr, tpss;
swizzle<T,n,1,2,0,1> yzxy, gbrg, tpst;
swizzle<T,n,1,2,0,2> yzxz, gbrb, tpsp;
swizzle<T,n,1,2,0,3> yzxw, gbra, tpsq;
swizzle<T,n,1,2,1,0> yzyx, gbgr, tpts;
swizzle<T,n,1,2,1,1> yzyy, gbgg, tptt;
swizzle<T,n,1,2,1,2> yzyz, gbgb, tptp;
swizzle<T,n,1,2,1,3> yzyw, gbga, tptq;
swizzle<T,n,1,2,2,0> yzzx, gbbr, tpps;
swizzle<T,n,1,2,2,1> yzzy, gbbg, tppt;
swizzle<T,n,1,2,2,2> yzzz, gbbb, tppp;
swizzle<T,n,1,2,2,3> yzzw, gbba, tppq;
swizzle<T,n,1,2,3,0> yzwx, gbar, tpqs;
swizzle<T,n,1,2,3,1> yzwy, gbag, tpqt;
swizzle<T,n,1,2,3,2> yzwz, gbab, tpqp;
swizzle<T,n,1,2,3,3> yzww, gbaa, tpqq;
swizzle<T,n,1,3,0,0> ywxx, garr, tqss;
swizzle<T,n,1,3,0,1> ywxy, garg, tqst;
swizzle<T,n,1,3,0,2> ywxz, garb, tqsp;
swizzle<T,n,1,3,0,3> ywxw, gara, tqsq;
swizzle<T,n,1,3,1,0> ywyx, gagr, tqts;
swizzle<T,n,1,3,1,1> ywyy, gagg, tqtt;
swizzle<T,n,1,3,1,2> ywyz, gagb, tqtp;
swizzle<T,n,1,3,1,3> ywyw, gaga, tqtq;
swizzle<T,n,1,3,2,0> ywzx, gabr, tqps;
swizzle<T,n,1,3,2,1> ywzy, gabg, tqpt;
swizzle<T,n,1,3,2,2> ywzz, gabb, tqpp;
swizzle<T,n,1,3,2,3> ywzw, gaba, tqpq;
swizzle<T,n,1,3,3,0> ywwx, gaar, tqqs;
swizzle<T,n,1,3,3,1> ywwy, gaag, tqqt;
swizzle<T,n,1,3,3,2> ywwz, gaab, tqqp;
swizzle<T,n,1,3,3,3> ywww, gaaa, tqqq;
swizzle<T,n,2,0,0,0> zxxx, brrr, psss;
swizzle<T,n,2,0,0,1> zxxy, brrg, psst;
swizzle<T,n,2,0,0,2> zxxz, brrb, pssp;
swizzle<T,n,2,0,0,3> zxxw, brra, pssq;
swizzle<T,n,2,0,1,0> zxyx, brgr, psts;
swizzle<T,n,2,0,1,1> zxyy, brgg, pstt;
swizzle<T,n,2,0,1,2> zxyz, brgb, pstp;
swizzle<T,n,2,0,1,3> zxyw, brga, pstq;
swizzle<T,n,2,0,2,0> zxzx, brbr, psps;
swizzle<T,n,2,0,2,1> zxzy, brbg, pspt;
swizzle<T,n,2,0,2,2> zxzz, brbb, pspp;
swizzle<T,n,2,0,2,3> zxzw, brba, pspq;
swizzle<T,n,2,0,3,0> zxwx, brar, psqs;
swizzle<T,n,2,0,3,1> zxwy, brag, psqt;
swizzle<T,n,2,0,3,2> zxwz, brab, psqp;
swizzle<T,n,2,0,3,3> zxww, braa, psqq;
swizzle<T,n,2,1,0,0> zyxx, bgrr, ptss;
swizzle<T,n,2,1,0,1> zyxy, bgrg, ptst;
swizzle<T,n,2,1,0,2> zyxz, bgrb, ptsp;
swizzle<T,n,2,1,0,3> zyxw, bgra, ptsq;
swizzle<T,n,2,1,1,0> zyyx, bggr, ptts;
swizzle<T,n,2,1,1,1> zyyy, bggg, pttt;
swizzle<T,n,2,1,1,2> zyyz, bggb, pttp;
swizzle<T,n,2,1,1,3> zyyw, bgga, pttq;
swizzle<T,n,2,1,2,0> zyzx, bgbr, ptps;
swizzle<T,n,2,1,2,1> zyzy, bgbg, ptpt;
swizzle<T,n,2,1,2,2> zyzz, bgbb, ptpp;
swizzle<T,n,2,1,2,3> zyzw, bgba, ptpq;
swizzle<T,n,2,1,3,0> zywx, bgar, ptqs;
swizzle<T,n,2,1,3,1> zywy, bgag, ptqt;
swizzle<T,n,2,1,3,2> zywz, bgab, ptqp;
swizzle<T,n,2,1,3,3> zyww, bgaa, ptqq;
swizzle<T,n,2,2,0,0> zzxx, bbrr, ppss;
swizzle<T,n,2,2,0,1> zzxy, bbrg, ppst;
swizzle<T,n,2,2,0,2> zzxz, bbrb, ppsp;
swizzle<T,n,2,2,0,3> zzxw, bbra, ppsq;
swizzle<T,n,2,2,1,0> zzyx, bbgr, ppts;
swizzle<T,n,2,2,1,1> zzyy, bbgg, pptt;
swizzle<T,n,2,2,1,2> zzyz, bbgb, pptp;
swizzle<T,n,2,2,1,3> zzyw, bbga, pptq;
swizzle<T,n,2,2,2,0> zzzx, bbbr, ppps;
swizzle<T,n,2,2,2,1> zzzy, bbbg, pppt;
swizzle<T,n,2,2,2,2> zzzz, bbbb, pppp;
swizzle<T,n,2,2,2,3> zzzw, bbba, pppq;
swizzle<T,n,2,2,3,0> zzwx, bbar, ppqs;
swizzle<T,n,2,2,3,1> zzwy, bbag, ppqt;
swizzle<T,n,2,2,3,2> zzwz, bbab, ppqp;
swizzle<T,n,2,2,3,3> zzww, bbaa, ppqq;
swizzle<T,n,2,3,0,0> zwxx, barr, pqss;
swizzle<T,n,2,3,0,1> zwxy, barg, pqst;
swizzle<T,n,2,3,0,2> zwxz, barb, pqsp;
swizzle<T,n,2,3,0,3> zwxw, bara, pqsq;
swizzle<T,n,2,3,1,0> zwyx, bagr, pqts;
swizzle<T,n,2,3,1,1> zwyy, bagg, pqtt;
swizzle<T,n,2,3,1,2> zwyz, bagb, pqtp;
swizzle<T,n,2,3,1,3> zwyw, baga, pqtq;
swizzle<T,n,2,3,2,0> zwzx, babr, pqps;
swizzle<T,n,2,3,2,1> zwzy, babg, pqpt;
swizzle<T,n,2,3,2,2> zwzz, babb, pqpp;
swizzle<T,n,2,3,2,3> zwzw, baba, pqpq;
swizzle<T,n,2,3,3,0> zwwx, baar, pqqs;
swizzle<T,n,2,3,3,1> zwwy, baag, pqqt;
swizzle<T,n,2,3,3,2> zwwz, baab, pqqp;
swizzle<T,n,2,3,3,3> zwww, baaa, pqqq;
swizzle<T,n,3,0,0,0> wxxx, arrr, qsss;
swizzle<T,n,3,0,0,1> wxxy, arrg, qsst;
swizzle<T,n,3,0,0,2> wxxz, arrb, qssp;
swizzle<T,n,3,0,0,3> wxxw, arra, qssq;
swizzle<T,n,3,0,1,0> wxyx, argr, qsts;
swizzle<T,n,3,0,1,1> wxyy, argg, qstt;
swizzle<T,n,3,0,1,2> wxyz, argb, qstp;
swizzle<T,n,3,0,1,3> wxyw, arga, qstq;
swizzle<T,n,3,0,2,0> wxzx, arbr, qsps;
swizzle<T,n,3,0,2,1> wxzy, arbg, qspt;
swizzle<T,n,3,0,2,2> wxzz, arbb, qspp;
swizzle<T,n,3,0,2,3> wxzw, arba, qspq;
swizzle<T,n,3,0,3,0> wxwx, arar, qsqs;
swizzle<T,n,3,0,3,1> wxwy, arag, qsqt;
swizzle<T,n,3,0,3,2> wxwz, arab, qsqp;
swizzle<T,n,3,0,3,3> wxww, araa, qsqq;
swizzle<T,n,3,1,0,0> wyxx, agrr, qtss;
swizzle<T,n,3,1,0,1> wyxy, agrg, qtst;
swizzle<T,n,3,1,0,2> wyxz, agrb, qtsp;
swizzle<T,n,3,1,0,3> wyxw, agra, qtsq;
swizzle<T,n,3,1,1,0> wyyx, aggr, qtts;
swizzle<T,n,3,1,1,1> wyyy, aggg, qttt;
swizzle<T,n,3,1,1,2> wyyz, aggb, qttp;
swizzle<T,n,3,1,1,3> wyyw, agga, qttq;
swizzle<T,n,3,1,2,0> wyzx, agbr, qtps;
swizzle<T,n,3,1,2,1> wyzy, agbg, qtpt;
swizzle<T,n,3,1,2,2> wyzz, agbb, qtpp;
swizzle<T,n,3,1,2,3> wyzw, agba, qtpq;
swizzle<T,n,3,1,3,0> wywx, agar, qtqs;
swizzle<T,n,3,1,3,1> wywy, agag, qtqt;
swizzle<T,n,3,1,3,2> wywz, agab, qtqp;
swizzle<T,n,3,1,3,3> wyww, agaa, qtqq;
swizzle<T,n,3,2,0,0> wzxx, abrr, qpss;
swizzle<T,n,3,2,0,1> wzxy, abrg, qpst;
swizzle<T,n,3,2,0,2> wzxz, abrb, qpsp;
swizzle<T,n,3,2,0,3> wzxw, abra, qpsq;
swizzle<T,n,3,2,1,0> wzyx, abgr, qpts;
swizzle<T,n,3,2,1,1> wzyy, abgg, qptt;
swizzle<T,n,3,2,1,2> wzyz, abgb, qptp;
swizzle<T,n,3,2,1,3> wzyw, abga, qptq;
swizzle<T,n,3,2,2,0> wzzx, abbr, qpps;
swizzle<T,n,3,2,2,1> wzzy, abbg, qppt;
swizzle<T,n,3,2,2,2> wzzz, abbb, qppp;
swizzle<T,n,3,2,2,3> wzzw, abba, qppq;
swizzle<T,n,3,2,3,0> wzwx, abar, qpqs;
swizzle<T,n,3,2,3,1> wzwy, abag, qpqt;
swizzle<T,n,3,2,3,2> wzwz, abab, qpqp;
swizzle<T,n,3,2,3,3> wzww, abaa, qpqq;
swizzle<T,n,3,3,0,0> wwxx, aarr, qqss;
swizzle<T,n,3,3,0,1> wwxy, aarg, qqst;
swizzle<T,n,3,3,0,2> wwxz, aarb, qqsp;
swizzle<T,n,3,3,0,3> wwxw, aara, qqsq;
swizzle<T,n,3,3,1,0> wwyx, aagr, qqts;
swizzle<T,n,3,3,1,1> wwyy, aagg, qqtt;
swizzle<T,n,3,3,1,2> wwyz, aagb, qqtp;
swizzle<T,n,3,3,1,3> wwyw, aaga, qqtq;
swizzle<T,n,3,3,2,0> wwzx, aabr, qqps;
swizzle<T,n,3,3,2,1> wwzy, aabg, qqpt;
swizzle<T,n,3,3,2,2> wwzz, aabb, qqpp;
swizzle<T,n,3,3,2,3> wwzw, aaba, qqpq;
swizzle<T,n,3,3,3,0> wwwx, aaar, qqqs;
swizzle<T,n,3,3,3,1> wwwy, aaag, qqqt;
swizzle<T,n,3,3,3,2> wwwz, aaab, qqqp;
swizzle<T,n,3,3,3,3> wwww, aaaa, qqqq;