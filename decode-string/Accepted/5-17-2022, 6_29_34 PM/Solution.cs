// https://leetcode.com/problems/decode-string

public class Solution {
	public string DecodeString(string s) {

		Stack<char>st = new Stack<char>();
		for (int i = 0; i < s.Length; i++)
		{
			if (s[i] != ']')
				st.Push(s[i]);
			else
			{
				string now = "";
				while (st.Peek() != '[')
				{
					now = st.Peek() + now;
					st.Pop();
				}
				st.Pop(); // '['
				int k_time = 0 , digit = 0;

				while (st.Count > 0 && ( st.Peek() - '0' >= 0 && st.Peek() - '0' <= 9) )
				{
					k_time += (int)Math.Pow(10, digit++) * (st.Peek() - '0');
					st.Pop();
				}
				
				while (k_time > 0)
				{
					for (int j = 0; j < now.Length; j++)
					{
						st.Push(now[j]);
					}
                    k_time--;
				}
			}

		}

		string ss = "";
		while (st.Count > 0)
		{
			ss = st.Peek() + ss;
			st.Pop();
		}

		return ss;

	}
}
