/* 
 * File:     main.cpp
 * Author:   Yıldırım Can Şehirlioğlu
 * Project:  Turing Machine implementation for palindromes
 * IDE:      NetBeans IDE 8.0
 * Compiler: MinGW
 * Created on May 27, 2014, 10:59 AM
 */

#include <cstdlib>
#include <iostream>


using namespace std;


int main(int argc, char** argv) {
    int head = 1; /*Since we assume the head of the Turing machine's tape is on the first character of the input
                  *I assigned this value with respect to the char array below (tape). It needs to be changed
                  *accordingly */
    
    /* Since it was stated in the homework pdf that we should assume that the input
     * string is in the tape I created some sample char arrays to simulate the tape of a Turing Machine. 
     * They can be interchanged as pleased. Don't forget to change the head marker above to the first alphabet character
     * of the string
     */
    //char tape[20] = {' ','a','b','b','b','b','a','b','b','b','b','a',' '};  
    //char tape[20] = {' ','a','b','a',' ',' ',' ',' ',' ',' ',' ',' ',' '};   
    //char tape[20] = {' ','b','a','b','a',' ',' ',' ',' ',' ',' ',' ',' '};    
    char tape[20] = {' ','b','a','b','a','b',' ',' ',' ',' ',' ',' ',' '};   
    //char tape[20] = {' ','b',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};   
    //char tape[20] = {' ','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};   
    //char tape[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};  
    //char tape[20] = {' ','a','b','b','a','b','b','b','a',' ',' ',' ',' '};   
    
    
//I labeled the reject states (q4 and q6) as qreject for convenience in the code)
    
//the machine will go into an infinite loop if it encounters an unrecognized character in the tape
    
/*incrementing the head variable means it simulates 
 * the effect of moving Right and decrementing 
 * it means moving Left*/
    
q0: switch(tape[head]){  //q0 state
    
    case ' ': //will do the transition from q0(start state) to q8(accept state) if the current head is empty
            cout<<"Current head location: tape["<<head<<"]"<<endl;
            cout<<"Transition from q0(start state) to q8(accept state)"<<endl;
            tape[head] = ' ';
            --head;
            cout<<"New head location: tape["<<head<<"]"<<endl<<endl;
q8:         cout<<"YES (the language is accepted)"<<endl;
            break;
        
    case 'a':  //if the current string starts with the character "a", will do a hypothetical transition to q1
            cout<<"Current head location: tape["<<head<<"]"<<endl;
            cout<<"string starts with the character 'a'"<<endl; 
            cout<<"Doing transition from q0 to q1"<<endl<<endl;
            tape[head] = ' '; //change the current character with empty char
            ++head; //head goes right
            cout<<"New state: q1"<<endl;
            cout<<"New head location: tape["<<head<<"]"<<endl<<endl;
            do {                            //q1 of turing machine, simulating the loop like transition
                if (tape[head] == 'a') {
                    tape[head] = 'a';
                    ++head;
                    cout<<"Read 'a'; New head location: tape["<<head<<"]"<<endl;
                }
                else if (tape[head] == 'b') {
                    tape[head] = 'b';
                    ++head;
                    cout<<"Read 'b'; New head location: tape["<<head<<"]"<<endl;
                }
                else if (tape[head] == ' ') {
                    tape[head] = ' ';
                    cout<<"Found empty char at head location: tape["<<head<<"]"<<endl;
                    --head;  //go left
                    cout<<"Head moved left, transition to q3"<<endl<<endl;
                    goto q3; //transition to q3
                }
            }while (1); 
q3:         cout<<"Current state: q3"<<endl;
            cout<<"Current head location tape["<<head<<"]"<<endl<<endl;
            if (tape[head] == 'b') {  //will do transition to q4, rejection state (a and b do not match)
                cout<<endl<<"Current state q4: The string can not be a palindrome since the first and last characters do not match"<<endl;
                cout<<endl<<"NO (the language is rejected)"<<endl;
                tape[head] = 'b';
                --head;
                goto qreject; //to halt the machine
            }
            else if (tape[head] == ' ') { //checking q3 to q8 transition possibility
                cout<<"Found empty char at head location tape["<<head<<"]"<<endl;
                tape[head] = ' ';
                --head;
                cout<<"Head moved left, transition to q8"<<endl<<endl;
                goto q8;  //go to accept state     
            }
            else if (tape[head] == 'a') { //q3 to q7 transition if the first and the last character matches
                tape[head] = ' ';
                --head;
                cout<<"Head moved left, transition from q3 to q7"<<endl<<endl;  
            }
            cout<<"Current state: q7"<<endl;
            cout<<"Current head location tape["<<head<<"]"<<endl<<endl;
            do {                            //q7 of turing machine, simulating the loop like transition
                if (tape[head] == 'a') {
                    tape[head] = 'a';
                    --head;
                    cout<<"Read 'a'; New head location: tape["<<head<<"]"<<endl;
                }
                else if (tape[head] == 'b') {
                    tape[head] = 'b';
                    --head;
                    cout<<"Read 'b'; New head location: tape["<<head<<"]"<<endl;
                }
                else if (tape[head] == ' ') {
                    tape[head] = ' ';
                    cout<<"Found empty char at head location: tape["<<head<<"]"<<endl;
                    ++head;  //go right
                    cout<<"Head moved right, transition to q0"<<endl<<endl;
                    goto q0; //transition to q0
                }
            }while (1);            
            break;
    
    case 'b': //if the current string starts with the character "b", transition to q2
            cout<<"Current head location: tape["<<head<<"]"<<endl;
            cout<<"string starts with the character 'b'"<<endl; 
            cout<<"Doing transition from q0 to q2"<<endl<<endl;
            tape[head] = ' '; //change the current character with empty char
            ++head; //head goes right
            cout<<"New state: q2"<<endl;
            cout<<"New head location: tape["<<head<<"]"<<endl<<endl;
            do {                            //q2 of turing machine, simulating the loop like transition
                if (tape[head] == 'a') {
                    tape[head] = 'a';
                    ++head;
                    cout<<"Read 'a'; New head location: tape["<<head<<"]"<<endl;
                }
                else if (tape[head] == 'b') {
                    tape[head] = 'b';
                    ++head;
                    cout<<"Read 'b'; New head location: tape["<<head<<"]"<<endl;
                }
                else if (tape[head] == ' ') {
                    tape[head] = ' ';
                    cout<<"Found empty char at head location: tape["<<head<<"]"<<endl;
                    --head;  //go left
                    cout<<"Head moved left, transition to q5"<<endl<<endl;
                    goto q5; //transition to q5
                }
            }while (1); 
q5:         cout<<"Current state: q5"<<endl;
            cout<<"Current head location tape["<<head<<"]"<<endl<<endl;
            if (tape[head] == 'a') {  //will do transition to q6, rejection state (b and a do not match)
                cout<<endl<<"Current state q6: The string can not be a palindrome since the first and last characters do not match"<<endl;
                cout<<endl<<"NO (the language is rejected)"<<endl;
                tape[head] = 'a';
                --head;
                goto qreject; //to halt the machine
            }
            else if (tape[head] == ' ') { //checking q5 to q8 transition possibility
                cout<<"Found empty char at head location tape["<<head<<"]"<<endl;
                tape[head] = ' ';
                --head;
                cout<<"Head moved left, transition to q8"<<endl<<endl;
                goto q8;  //go to accept state     
            }
            else if (tape[head] == 'b') { //q5 to q7 transition if the first and the last character matches
                tape[head] = ' ';
                --head;
                cout<<"Head moved left, transition from q5 to q7"<<endl<<endl;  
            }
            cout<<"Current state: q7"<<endl;
            cout<<"Current head location tape["<<head<<"]"<<endl<<endl;
            do {                            //q7 of turing machine, simulating the loop like transition
                if (tape[head] == 'a') {
                    tape[head] = 'a';
                    --head;
                    cout<<"Read 'a'; New head location: tape["<<head<<"]"<<endl;
                }
                else if (tape[head] == 'b') {
                    tape[head] = 'b';
                    --head;
                    cout<<"Read 'b'; New head location: tape["<<head<<"]"<<endl;
                }
                else if (tape[head] == ' ') {
                    tape[head] = ' ';
                    cout<<"Found empty char at head location: tape["<<head<<"]"<<endl;
                    ++head;  //go right
                    cout<<"Head moved right, transition to q0"<<endl<<endl;
                    goto q0; //transition to q0
                }
            }while (1);            
            break;
        
    default:
            cout<<"Unrecognized character"<<endl;
            cout<<"NO (the language is rejected)"<<endl;
            break;
    }

qreject: system("pause");      
return 0;
}

