# Write your MySQL query statement below
select MAX(num) as num
from (
    select num
    FROM MyNumbers
    group by num
    HAVING COUNT(num)=1
) as Singleumbers;