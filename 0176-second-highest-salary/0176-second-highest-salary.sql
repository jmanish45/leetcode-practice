# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
From EMPLOYEE
WHERE salary < (
    SELECT MAX(salary) FROM EMPLOYEE
);