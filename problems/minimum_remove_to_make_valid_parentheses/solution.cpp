class Solution {
public:
	string minRemoveToMakeValid(string s) {
		vector<char> stack;
		int countL=0;
		int countR=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				countL++;
			}
			if(s[i]==')'){
				if(countR>=countL){
					cout<<countR<<endl;
					continue;
				}
				countR++; 
			}
			stack.push_back(s[i]);
		}
		string res;
		while(countL>countR){
			int flag=stack.size()-1;
			while(stack[flag]!='('){
				flag--;
			}
			stack.erase(stack.begin()+flag);
			countL--;
		}
		for(int i=0;i<stack.size();i++){
			res+=stack[i];
		}
		return res;
	}
};