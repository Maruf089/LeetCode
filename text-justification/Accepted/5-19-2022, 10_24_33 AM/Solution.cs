// https://leetcode.com/problems/text-justification

public class Solution {

    public string left_justify(string [] word , int diff , int i , int j)
    {
        int num_of_word = j - i ;
        int gap = num_of_word - 1;
        int space_right = diff - gap;

        StringBuilder res = new StringBuilder(word[i]);
        for(int k = i+1 ; k<j;k++)
        {
            res.Append(' ');
            res.Append(word[k]);
        }
        int remaining = space_right;
        while(remaining > 0) {
            res.Append(' ');
            remaining--;
        }
        return res.ToString();
    }

    public string middle_justify(string [] word , int diff , int i , int j)
    {
        int num_of_word = j - i ;
        int spaces = diff / (num_of_word - 1);
        int extra = diff % (num_of_word - 1);

        StringBuilder res = new StringBuilder(word[i]);
        for(int k = i+1 ; k<j;k++)
        {
            int remaining = spaces + ( extra > 0 ? 1 : 0 );
            extra--;
            while(remaining > 0)
                {
                    res.Append(' ');
                    remaining -= 1;
                }
            res.Append(word[k]);
        }
        return res.ToString();
    }

    public List<string> FullJustify(string[] word, int maxWidth) {

        List<string>result = new List<string>();
        int i = 0 , n = word.Length;
        while(i<n)
        {
            int j = i + 1;
            int linelen = word[i].Length;
            while(j < n && linelen + word[j].Length + ( j - i - 1) < maxWidth)
            {
                linelen = linelen + word[j].Length;
                j++;
            }
            int diff = maxWidth - linelen;
            int num_of_word = j - i ;
            if(num_of_word == 1 || j >= n)
            {
                // left justified
                result.Add(left_justify(word , diff , i , j ));
            }
            else
            {
                // middle justify
                result.Add(middle_justify(word , diff , i , j ));
            }

            i = j ;
        }

        return result;

    }
}
