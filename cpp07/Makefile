
all:
	make -C ex00/
	make -C ex01/
	make -C ex02/

clean:
	make clean -C ex00/
	make clean -C ex01/
	make clean -C ex02/
	rm -rf $(OBJDIR)

fclean:			clean
	make fclean -C ex00/
	make fclean -C ex01/
	make fclean -C ex02/

re:
	make re -C ex00/
	make re -C ex01/
	make re -C ex02/

.PHONY:			all clean fclean re 