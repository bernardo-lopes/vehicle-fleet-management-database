select colaborador.nome as Colaborador, colaborador.cargo as Cargo, colaborador.departamento as Departamento, count(atribuicao.id) as "Nº de anos com viatura" from atribuicao right join colaborador on atribuicao.id=colaborador.id group by colaborador.id order by count(atribuicao.id) desc