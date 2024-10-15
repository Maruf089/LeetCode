// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        
       stack<char>st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ']')
			st.push(s[i]);
		else
		{
			string now = "";
			while (st.top() != '[')
			{
				now = st.top() + now;
				st.pop();
			}
			st.pop(); // '['
			string number = "";

			while (st.size() and isdigit(st.top()))
			{
				number = st.top() + number;
				st.pop();
			}
			int k_time = stoi(number);
			while (k_time--)
			{
				for (int j = 0; j < now.size(); j++)
				{
					st.push(now[j]);
				}
			}
		}

	}

	string ss = "";
	while (st.size())
	{
		ss = st.top() + ss;
		st.pop();
	}
        
        return ss;

        
        
        
        
    }
};