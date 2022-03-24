SELECT 
    colaborador.nome AS Nome,
    CONCAT(colaborador.cargo,
            ' ',
            LCASE(colaborador.departamento)) AS 'Posição',
    abastecimento.matricula AS 'Matrícula',
    COUNT(*) AS 'Nº de Abastecimentos',
    CAST(SUM(preco) AS DECIMAL (9 , 2 )) AS 'Consumos [€]'
FROM
    (colaborador
    INNER JOIN atribuicao ON colaborador.id = atribuicao.id)
        INNER JOIN
    abastecimento ON atribuicao.matricula = abastecimento.matricula
WHERE
    YEAR(abastecimento.a_data) = atribuicao.ano
        AND YEAR(abastecimento.a_data) = 2019
GROUP BY colaborador.nome , CONCAT(colaborador.cargo,
        ' ',
        LCASE(colaborador.departamento)) , abastecimento.matricula
ORDER BY colaborador.nome