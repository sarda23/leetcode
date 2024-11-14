# Write your MySQL query statement below

select w1.id as id
from Weather w1
join Weather w2
ON w1.recordDate = w2.recordDate + INTERVAL 1 DAY
where w1.temperature > w2.temperature;