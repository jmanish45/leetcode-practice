SELECT employee_id FROM Employees
WHERE 
SALARY < 30000 AND 
manager_id not  in (SELECT employee_id from Employees ) 
order by employee_id
