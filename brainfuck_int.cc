#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int MAX_MEMORY = 30000; //#The number of 8 bit memory cells that the original brainfuck had  
//you should show how brainfuck works, jej

int main(){
    vector<char> memory(MAX_MEMORY, 0);
    vector<char> instructions;
    stack<int> pos_buc;
    int pointer = 0;
    char inp;

    while(cin>>inp and inp != '!'){
        instructions.push_back(inp);
    }

    for(int i = 0; i<instructions.size(); ++i){
        switch (instructions[i]) {
            case '+':
                memory[pointer]++;
                break;
            case '-':
                memory[pointer]--;
                break;
            case '>':
                pointer++;
                break;
            case '<':
                pointer--;
                break;
            case '[':
                pos_buc.push(i);
                break;
            case ']':
                if(memory[pointer] == 0) pos_buc.pop();
                else i = pos_buc.top();
                break;
            case '.':
                cout<<memory[pointer];
                break;
            case ',':
                char a;
                cout<<"----ENTER A CHAR----"<<endl;
                cin>>a;
                memory[pointer] = a;
                break;

        }
    }
}
