INSERT INTO t_article VALUES
(NULL, 'Scop', 'https://cdn.intrav2.42.fr/video/video/227/scop.mp4', 'https://cdn.intrav2.42.fr/video/video/227/scop_sthumb_20.png', 'https://projects.intrav2.42.fr/uploads/document/document/123/scop.pdf');
INSERT INTO t_article VALUES
(NULL, 'RT', 'https://cdn.intrav2.42.fr/video/video/101/rtv1-rt.mp4', 'https://cdn.intrav2.42.fr/video/video/101/rtv1-rt_sthumb_90.png', 'https://cdn.intrav2.42.fr/pdf/pdf/33/rt.pdf');
INSERT INTO t_article VALUES
(NULL, '42run', "https://cdn.intrav2.42.fr/video/video/232/42run.mp4", 'https://cdn.intrav2.42.fr/video/video/232/42run_sthumb_0.png', 'https://projects.intrav2.42.fr/uploads/document/document/134/42run.pdf');

INSERT INTO t_user VALUES /* pass is '@dm1n' */
(NULL, 'admin', 'gqeuP4YJ8hU3ZqGwGikB6+rcZBqefVy+7hTLQkOD+jwVkp4fkS7/gr1rAQfn9VUKWc7bvOD7OsXrQQN5KGHbfg==', 'EDDsl&fBCJB|a5XUtAlnQN8', 'ROLE_ADMIN');
INSERT INTO t_user VALUES /* pass is 'john' */
(NULL, 'JohnDoe', 'L2nNR5hIcinaJkKR+j4baYaZjcHS0c3WX2gjYF6Tmgl1Bs+C9Qbr+69X8eQwXDvw0vp73PrcSeT0bGEW5+T2hA==', 'YcM=A$nsYzkyeDVjEUa7W9K', 'ROLE_USER');
INSERT INTO t_user VALUES /* pass is 'jane' */
(NULL, 'JaneDoe', 'EfakNLxyhHy2hVJlxDmVNl1pmgjUZl99gtQ+V3mxSeD8IjeZJ8abnFIpw9QNahwAlEaXBiQUBLXKWRzOmSr8HQ==', 'dhMTBkzwDKxnD;4KNs,4ENy', 'ROLE_USER');

INSERT INTO t_comment VALUES (NULL, 'Great!', 1, 1);
INSERT INTO t_comment VALUES (NULL, "Thank you, I'll try my best.", 1, 2);
