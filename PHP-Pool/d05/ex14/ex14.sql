SELECT etage_salle "etage", SUM(nbr_siege) "sieges" FROM salle GROUP BY etage_salle ORDER BY sieges DESC;