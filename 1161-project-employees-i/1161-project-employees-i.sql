SELECT p.project_id , ROUND(AVG(e.experience_years), 2) AS average_years
from PROJECT AS p
left join Employee AS e
ON p.employee_id = e.employee_id
GROUP BY p.project_id
