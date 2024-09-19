# Write your MySQL query statement below
select unique_id , name
from employees as emp
left join employeeUNI as uni
on uni.id = emp.id

-- we want every name from employee table 
-- so emp will be before left join