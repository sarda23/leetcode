-- WITH ProcessTimes AS (
--     SELECT 
--         machine_id,
--         process_id,
--         MAX(CASE WHEN activity_type = 'end' THEN timestamp END) -
--         MAX(CASE WHEN activity_type = 'start' THEN timestamp END) AS process_time
--     FROM Activity
--     GROUP BY machine_id, process_id
-- )
-- SELECT 
--     machine_id,
--     ROUND(AVG(process_time), 3) AS processing_time
-- FROM ProcessTimes
-- GROUP BY machine_id;

SELECT 
    a1.machine_id,
    ROUND(AVG(a2.timestamp - a1.timestamp), 3) AS processing_time
FROM 
    Activity a1
JOIN 
    Activity a2
ON 
    a1.machine_id = a2.machine_id 
    AND a1.process_id = a2.process_id
    AND a1.activity_type = 'start'
    AND a2.activity_type = 'end'
GROUP BY 
    a1.machine_id;
