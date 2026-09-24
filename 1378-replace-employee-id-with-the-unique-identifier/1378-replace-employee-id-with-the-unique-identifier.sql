# Write your MySQL query statement below
SELECT u.unique_id as unique_id , e.name as name 
FROM EMPLOYEES e
LEFT JOIN
EmployeeUNI u
ON e.id = u.id
