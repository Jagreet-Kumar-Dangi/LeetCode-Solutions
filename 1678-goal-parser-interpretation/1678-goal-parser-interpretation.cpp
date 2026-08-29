class Solution {
public:
    string interpret(string command) {
        string s="";
        for(int i=0;i<command.size();i++){
            if(command[i]=='G')
                s +='G';
            else if(command[i]=='(' && command[i+1] !='a')
                s+='o';
            else if(command[i]=='(' && command[i+1] =='a')
                s+="al";
        }
        return s;
    }
};