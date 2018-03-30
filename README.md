# Check convert string to number 
	Allowed characters
		0123456789-+.e

	Tokens
		-	s sign 	 	(-+)
		8	n number 	(0123456789)
		.	p point	 	(.)
		e	e exponent 	(e)

	Rules							All correct variants
	   8 (n)	e8 (n)  e-8 (sn)	(   8,   8e8,    8e-8 )
	  -8 (sn)	e8 (n)	e-8 (sn)	(  -8,   -8e8,  -8e-8 )

	  .8 (pn)	e8 (n)	e-8 (sn)	(  .8,   .8e8,  .8e-8 )
	  8. (np)	e8 (n)	e-8 (sn)	(  8.,   8.e8,  8.e-8 )

	 -8. (snp)	e8 (n)	e-8 (sn)	( -8.,  -8.e8,  -8.e-8)
     -.8 (spn)	e8 (n)	e-8 (sn)	( -.8,  -.8e8,  -.8e-8)

	 8.8 (npn)	e8 (n)	e-8	(sn)	( 8.8,  8.8e8,  8.8e-8)
	-8.8 (snpn)	e8 (n)	e-8	(sn)	(-8.8, -8.8e8, -8.8e-8)

### Some examples
```sh
/* true */ isNumber("12e-12");
/* true */ isNumber("-12e-12");
/* true */ isNumber(".12e-12");
/* true */ isNumber("12.e-12");
/* true */ isNumber("12.12e-12");
/* true */ isNumber("-.12e-12");
/* true */ isNumber("-12.e-12");
/* true */ isNumber("-12.12e-12");
/* true */ isNumber("8e+90900909887767867867867867867867868");
/* true */ isNumber("-8e34");
/* true */ isNumber("-0000e-0");
/* true */ isNumber("-0000");
/* true */ isNumber("+0e+0");
/* true */ isNumber("-12.");
/* true */ isNumber("   0.90   ");
/* true */ isNumber("45.90e-1");
/* true */ isNumber("-.8e23");
/* true */ isNumber(".234");
/* true */ isNumber(".4e34");
/* true */ isNumber("8.90e1");
/* true */ isNumber("0000123.89e2324");
/* true */ isNumber("-890");
/* true */ isNumber("123");
/* true */ isNumber("+234.432e+2341232");
/* false */ isNumber("8-");
/* false */ isNumber("8.-");
/* false */ isNumber("8-.");
/* false */ isNumber("7987e08098e-099809");
/* false */ isNumber(" ");
/* false */ isNumber("");
/* false */ isNumber("1e1.");
/* false */ isNumber("-0000e-00.3");
/* false */ isNumber("    ");
/* false */ isNumber("f");
/* false */ isNumber("-.");
/* false */ isNumber("..");
/* false */ isNumber("abcd");
/* false */ isNumber("19 7");
/* false */ isNumber("3.434e2.3");
/* false */ isNumber(".5e.23");
/* false */ isNumber("3.434.");
/* false */ isNumber("k8980");
/* false */ isNumber("--234");
/* false */ isNumber("345,908");
/* false */ isNumber("123.67.90");
/* false */ isNumber("123e342-");
/* false */ isNumber("3.4e4-");
/* false */ isNumber("3.4e");
/* false */ isNumber("12312ee");
/* false */ isNumber("e89");
```