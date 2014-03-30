#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

bool SpeciL(char l){
	if (l == '{' ||
            l == '[' ||
            l == '(' ||
            l == '<')
    {
		return 1;
    } else
		return 0;
}// function to specify left part

bool SpeciR(char r){
    if (r == '}' ||
        r == ']' ||
        r == ')' ||
        r == '>')
    {
        return 1;
    } else
        return 0;
}// function to specify right part

bool Specilegal(char leg){
    if (leg == '}' || leg == '{' ||
        leg == ']' || leg == '[' ||
        leg == ')' || leg == '(' ||
        leg == '>' || leg == '<' ||
        leg == '\n' || leg == EOF)
    {
        return 1;
    } else
        return 0;
}// function to specify right part

// function to judge string or not
bool JudgStr(char b){
    stack<char> mystack;//initial stack
    
    do{
        //while(Specilegal(b)){
        
        while (SpeciL(b)) {//push left part into stack till other character input
            mystack.push(b);
            //cout<<b<<endl;
            b=getchar();//get next character
        }
        
        while (SpeciR(b)) {//check if right part
            if (mystack.empty() == 1) {
                return 0;
            }//nothing before first right part=>not string
            
            switch(b) {//match the right part with previous one
                case (')'):
                    if ('('==mystack.top()) {//if they are in pair
                        mystack.pop();//pop top(previous one)
                        break;
                    } else//if they are not in pair
                        return 0;//stack is not empty=>not string
                case (']'):
                    if ('['==mystack.top()) {
                        mystack.pop();//pop top(previous one)
                        break;
                    } else
                        return 0;//stack is not empty=>not string
                case ('>'):
                    if ('<'==mystack.top()) {
                        mystack.pop();//pop top(previous one)
                        break;
                    } else
                        return 0;//stack is not empty=>not string
                case ('}'):
                    if ('{'==mystack.top()) {
                        mystack.pop();//pop top(previous one)
                        break;
                    } else
                        return 0;//stack is not empty=>not string
            }
            
            //cout<<b<<endl;
            b=getchar();//get next character
        }
        
        if(b==EOF)//if end of file then break
            break;
        else if (Specilegal(b)==0)
            return 0;
    } while(b!='\n');//check every character till endl
    
    return mystack.empty();//stack is  empty=>string
} //stack is not empty=>not string


int main()
{
    int n;//# of of test cases
    char c,e;//c=character, e=the first '\n'

    freopen("input.txt","r",stdin);//open file
    cin>>n;
    //cout<<"n=" <<n<< endl;
    e=getchar();//get first '/n'

    for (int i=1;i<=n;i++) {//execute n judges
        c=getchar();
    
        if(JudgStr(c)==1)//stack is  empty=>string
            cout<<"Case "<<i<<": Yes\n";
        else {//stack is not empty=>not string
            cout<<"Case "<<i<<": No\n";
            while(c!='\n') {//get next character till endl
                c=getchar();
                if(c==EOF)//if end of file then break
                    break;
            }
        }
    }
    
    return 0;
}
