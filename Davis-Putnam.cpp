#include <iostream>
#include <string>
using namespace std;
char Negation(char c) {
    if (c >= 'A' && c <= 'Z')
        return (char)(c + 32);
    else if (c >= 'a' && c <= 'z')
        return (char)(c - 32);
    else return c;
}
string suppliteral(string str, char x ) {
    string result = "{",result2;
    bool trouver=false;
    int i = 1;
    while ( i < str.length()-1 ) {
        if (str[i] == '{' ) {
            result2 = "";
            trouver = false;
            while (str[i-1] != '}') {
                if (str[i]==x)
                    trouver=true;
                if(str[i]!=Negation(x) )
                    if (str[i]!=',' || str[i+1]!=Negation(x) &&  (str[i]!= ',' || str[i-1]!=Negation(x)) )
                         result2 += str[i];
                i++;
            }
            if (trouver==false) {
                if((2 < result.length() ) )  result2 = ","+result2;
                result += result2;
            }
        }
        i++;
    }
    result += "}";
    return result;
}
bool verificationclausevide(string str) {
    int i = 1;
    while ( i < str.length()-1 ) {
        if (str[i]=='{'&& str[i+1]=='}')
            return true;
        i++;
    }
    return false;
}
bool aucunclause(string str) {
    if (str[0]=='{'&& str[1]=='}')
        return true;
    else  return false;
}
char Literal_X(string str) {
    for (int i = 1; i<str.length() -1; i++) {
        if (( (str[i] >= 'a' && str[i]  <= 'z') || (str[i] >= 'A' && str[i]  <= 'Z') ) && (str[i-1]=='{' && str[i+1]=='}') )
            return str[i] ;
    }
    return '0' ;
}
char Literal_Y(string str) {
    int i,j ;
    bool test = true;
    char x;
    for (i = 1; i<str.length()-1; i++) {
        x=Negation(str[i]);
        j = i+1;
        while ( j < str.length()-1 && test ) {
            if (str[j]==x)
                test=false;
            j++ ;
        }
        if (test)
            return(str[i]);
    }
    return '0';
}
char Literal_Z(string str) {
    for (int i = 1; i<str.length() -1; i++) {
        if ( (str[i] >= 'a' && str[i]  <= 'z') || (str[i] >= 'A' && str[i]  <= 'Z') )
            return str[i] ;
    }
    return '0' ;
}
bool Formule(string str) {
    bool satisfiable= false, ClauseVide=false;
    do { cout<< str <<endl; 
        if (aucunclause(str))
            satisfiable = true;
        else if (Literal_X(str)!='0')
            str=suppliteral(str,Literal_X(str));
        else if (Literal_Y(str)!='0')
            str=suppliteral(str,Literal_Y(str));
        else if (Literal_Z(str)!='0') { 
            if (Formule(suppliteral(str,Literal_Z(str))))
                satisfiable=true;
            else {
                cout<< endl;
                str=suppliteral(str,Negation(Literal_Z(str)));
            }
              
        }
        if (verificationclausevide(str))
            ClauseVide =true;
    } while ( satisfiable ==false && ClauseVide ==false ) ;
    return satisfiable ;
}
int main () {
    string str;
    cout << "Entrez une Formule  : ";
    getline(cin, str); cout<< endl<<endl;
    if ( Formule(str) )
        cout<< " la formule est satisfiable." << endl;
    else
        cout<< " la formule est insatisfiable !" << endl;
    return 0;
}