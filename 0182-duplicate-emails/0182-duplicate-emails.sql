# Write your MySQL query statement below
select email
from Person
GROUP BY email
having count(email)>1;