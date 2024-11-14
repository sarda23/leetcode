# Write your MySQL query statement below
update Salary
SET sex = CASE
            When sex = 'm' THEN 'f'
            WHEN sex = 'f' THEN 'm'
          END;