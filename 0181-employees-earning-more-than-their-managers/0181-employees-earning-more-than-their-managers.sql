# Write your MySQL query statement below
select E1.name as Employee 
from Employee as E1
Join Employee as E2 on E1.ManagerId  = E2.Id
where E1.salary > E2.salary