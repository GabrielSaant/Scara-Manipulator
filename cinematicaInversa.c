#include <stdio.h>
#include <math.h>
#include <plplot/plplot.h> 


#define PI 3.14159265358979323846

int cinematicaInversaScara(double x, double y, double a1, double a2, double *theta1, double *theta2) {
    double distancia = sqrt(x*x + y*y);
    double min_distancia = fabs(a1 - a2);

    if (distancia > (a1 + a2) || distancia < min_distancia) {
        return -1;
    }

    double cos_theta2 = (x*x + y*y - a1*a1 - a2*a2) / (2*a1*a2);
    if (cos_theta2 < -1 || cos_theta2 > 1) {
        return -1;
    }

    *theta2 = acos(cos_theta2);
    double alpha = atan2(y, x);
    double beta = atan2(a2 * sin(*theta2), (a1 + a2 * cos(*theta2)));
    *theta1 = alpha - beta;

    *theta1 *= 180.0 / PI; 
    *theta2 *= 180.0 / PI;

    return 0;
}

void plotarBracoSCARA(double theta1_deg, double theta2_deg, double a1, double a2) {

    double theta1 = theta1_deg * PI / 180.0;
    double theta2 = theta2_deg * PI / 180.0;

    // Coordenadas das juntas
    double x0 = 0.0, y0 = 0.0;
    double x1 = a1 * cos(theta1);
    double y1 = a1 * sin(theta1);
    double x2 = x1 + a2 * cos(theta1 + theta2);
    double y2 = y1 + a2 * sin(theta1 + theta2);

    // Configuração do PLplot
    plsdev("xcairo");
    plinit();

    // Configuração do gráfico
    double margem = 0.5;
    plenv(-(a1+a2)-margem, (a1+a2)+margem, -(a1+a2)-margem, (a1+a2)+margem, 1, 1);

    // Desenha eixos
    plcol0(8); // Cinza
    pljoin(x0, y0, (a1+a2)+margem, y0); // Eixo X
    pljoin(x0, y0, x0, (a1+a2)+margem); // Eixo Y

    // Desenha braços
    plcol0(9); // Vermelho
    pljoin(x0, y0, x1, y1); // Braço 1
    plcol0(4); // Azul
    pljoin(x1, y1, x2, y2); // Braço 2

    // Marca juntas
    plcol0(3); // Verde
    plpoin(1, &x1, &y1, 2);  // Junta 1
    plpoin(1, &x2, &y2, 17); // Efetuador

    // Rótulos
    plcol0(10); // Preto
    pllab("Eixo X (m)", "Eixo Y (m)", "SCARA");

    plend();
}

int main() {
    double x, y, theta1, theta2, a1, a2;
    
    
    printf("Valor de x e y: ");
    scanf("%lf %lf", &x, &y);
    printf("Valor de a1 e a2: ");
    scanf("%lf %lf", &a1, &a2);

 
    int resultado = cinematicaInversaScara(x, y, a1, a2, &theta1, &theta2);

    if (resultado == 0) {
        printf("Theta1: %.2f\n", theta1);
        printf("Theta2: %.2f\n", theta2);
        plotarBracoSCARA(theta1, theta2, a1, a2);
    } else {
        printf("Erro: Fora de alcance.\n");
    }

    return 0;
}
