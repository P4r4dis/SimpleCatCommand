#include "../include_test/test.hpp"

// void    redirect_all_stdout(void)
// {
//         cr_redirect_stdout();
//         cr_redirect_stderr();
// }

// int     error(void)
// {
//         write(2, "error", 5); // stdoout = 1 and stderr = 2
//         return(0);
// }



// int     check_if_no_params(unsigned int ac)
// {
//         if (ac == 1 || ac < 2)
//                 std::cerr << "my_cat : Usage : ./my_cat file [...]";
//         return EXIT_SUCCESS;
// }

// int     check_if_params(unsigned int ac)
// {
//         if (ac >= 2)
//                 return EXIT_SUCCESS;
// }

int main(int ac, char **av)
{
        printf("ac0 = %d\nac1 = %d\nac2 = %d\n", ac, ac, ac);
        printf("result of MARCO EXIT_SUCCESS : %d\n", EXIT_SUCCESS);
        printf("result of MARCO EXIT_FAILURE : %d\n", EXIT_FAILURE);

        // check_is_null_params(ac);
        if(!av)
                return 1;
        return EXIT_SUCCESS;
}