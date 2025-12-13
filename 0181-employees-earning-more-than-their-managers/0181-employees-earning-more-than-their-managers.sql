SELECT e1.name as EMPLOYEE
FROM EMPLOYEE as e1
WHERE e1.salary > (
    SELECT e2.salary FROM EMPLOYEE e2
    where e2.id = e1.managerId
)

-- SELECT e1.name as Employee
-- FROM Employee e1
-- JOIN Employee e2
-- on  e1.managerID = e2.id
-- WHERE e1.salary > e2.salary




