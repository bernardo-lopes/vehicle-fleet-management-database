SELECT 
    colaborador.nome AS Nome,
    colaborador.cargo AS Cargo,
    colaborador.departamento AS Departamento,
    abastecimento.matricula AS 'Matrícula',
    YEAR(abastecimento.a_data) AS Ano,
    CAST(SUM(preco) AS DECIMAL (9 , 2 )) AS 'Consumos [€]'
FROM
    (colaborador
    INNER JOIN atribuicao ON colaborador.id = atribuicao.id)
        INNER JOIN
    abastecimento ON atribuicao.matricula = abastecimento.matricula
WHERE
    YEAR(abastecimento.a_data) = atribuicao.ano
GROUP BY colaborador.id , colaborador.nome , CONCAT(colaborador.cargo,
        ' ',
        LCASE(colaborador.departamento)) , abastecimento.matricula , YEAR(abastecimento.a_data)
ORDER BY SUM(preco) DESC
LIMIT 10