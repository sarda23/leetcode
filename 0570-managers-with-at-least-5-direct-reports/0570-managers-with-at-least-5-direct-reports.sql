select e1.name
from Employee e1
JOIN Employee e2 
on e1.id = e2.managerId
-- group by - both id and name - to be unique
group by e1.id,e1.name
HAVING count(e1.id) >= 5;