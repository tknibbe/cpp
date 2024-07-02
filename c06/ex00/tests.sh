#/bin/bash


#char tests
./executable C
./executable P
./executable '	'
./executable ' '

# # #int tests
./executable 42
./executable 0
./executable -42
./executable 2147483648
./executable -2147483649

# #float tests
./executable 420.69f
./executable 420.694206942069f
./executable -420.69f
./executable 999999999999999999999999999999999999903.f #out of range for a float

# #double tests
./executable 999999999999999999999999999999999999903.0 #out of range for a float
./executable 420.694206942069
./executable 420.0
./executable -999999999999999999999999999999999999903.0 #out of range for a float
./executable 1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583690.000000 #out of range for double
#TODO what to test here? should just be able to handle more than int?

# pseudo tests
./executable nan
./executable nanf
./executable +inf
./executable -inf
./executable inf
./executable inff
./executable -inff
./executable +inff