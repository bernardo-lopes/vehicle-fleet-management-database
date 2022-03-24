SELECT 
    colaborador.nome AS Nome,
    abastecimento.matricula AS 'Matrícula',
    YEAR(abastecimento.a_data) AS Ano,
    CAST(SUM(preco) AS DECIMAL (9 , 2 )) AS 'Consumos [€]',
    CAST((SUM(preco) - 500) AS DECIMAL (9 , 2 )) AS 'Diferença [€]'
FROM
    (colaborador
    INNER JOIN atribuicao ON colaborador.id = atribuicao.id)
        INNER JOIN
    abastecimento ON atribuicao.matricula = abastecimento.matricula
WHERE
    YEAR(abastecimento.a_data) = atribuicao.ano
GROUP BY colaborador.id , colaborador.nome , colaborador.cargo , colaborador.departamento , abastecimento.matricula , YEAR(abastecimento.a_data)
HAVING SUM(preco) >= 500
ORDER BY (SUM(preco) - 500) DESC