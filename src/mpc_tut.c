#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
        //creating parsers for Nouns and Adjectives
        //mpc_paser_t* creates parsers
        //mpc_or creates parser where one or several options should be used
        //mpc_sym wraps initial strings
        mpc_parser_t* Adjective = mpc_or(4, mpc_sym("wow"), mpc_sym("many"),
                                  mpc_sym("so"), mpc_sym("such"));
        
        mpc_parser_t* Noun  		= mpc_or(5, mpc_sym("lisp"), mpc_sym("language"),
                                  mpc_sym("book"), mpc_sym("build"), mpc_sym("c"));
        
        //defining a phrase
        //mpc_and specifies one thing is required then another
        //mpcf_strfold, free specifies how to join or delete input from parsers
        mpc_parser_t* Phrase    = mpc_and(2, mpcf_strfold, Adjective, Noun, free);
        
        mpc_parser_t* Doge      = mpc_many(mpcf_stfold, Phrase);
        
        //a cleaner and less messy way to create ^
}
