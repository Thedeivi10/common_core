
COMPOSE_PATH = srcs/docker-compose.yml

NAME = inception

all:
	@printf "Running inception.\n" 
	docker-compose -f $(COMPOSE_PATH) up -d --build

down:
	docker-compose -f $(COMPOSE_PATH) down

clean:
	@printf "Cleaning the configuration of inception.\n"
	@docker compose -f $(COMPOSE_PATH) down --volumes --rmi all || true

fclean:
	@printf "Complete cleanup of all docker configurations\n"
	@docker compose -f $(COMPOSE_PATH) down --volumes --rmi all || true
	@docker stop $$(docker ps -qa) || true
	@docker rm $$(docker ps -qa) || true
	@docker rmi -f $$(docker images -qa) || true
	@docker volume rm $$(docker volume ls -q) || true
	@docker network rm $$(docker network ls -q) 2>/dev/null || true

re: fclean all

ps:
	docker compose -f $(COMPOSE_PATH) ps

.PHONE: all clean fclean re ps