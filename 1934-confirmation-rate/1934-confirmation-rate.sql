# Write your MySQL query statement below
select s.user_id ,
    round(AVG(
        Case
            when c.action="confirmed" then 1.00
            else 0
        end
    ), 2)
as confirmation_rate 
from Signups s
Left Join Confirmations c ON s.user_id = c.user_id
group by s.user_id