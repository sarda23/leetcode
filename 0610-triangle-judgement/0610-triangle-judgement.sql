# Write your MySQL query statement below
select x,y,z,
case  when x+y>z and x+z>y and y+z>x 
        THEN 'Yes'
        else 'No'
    END AS triangle
FROM Triangle;