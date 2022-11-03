# inclui  " Escultor.h "
# inclui  < iostream >
# inclui  < stdlib.h >
# inclui  < cmath >
# inclui  < fstream >

usando  namespace  std ;

Sculptor::Sculptor ( int _nx, int _ny, int _nz){ // instancia uma classe e alocação da matriz
     nx = _nx;
     ny = _ny;
     nz = _nz;

     r = 0 ;
     g = 0 ;
     b = 0 ;
     a = 0 ;

     v = novo Voxel**[_nx]; // alocação de memória da 1 dimensão da matriz
     for ( int i= 0 ; i<_nx; i++){
         v[i] = novo Voxel*[_ny]; // alocação de memória da 2 dimensão da matriz

         for ( int j= 0 ; j<_ny; j++){
             v[i][j] = novo Voxel [_nz]; // alocação de memória da 3 dimensão da matriz

             for ( int k= 0 ; k<_nz; k++){
                 this -> v[i][j][k]. r = 0 ;
                 this -> v[i][j][k]. g = 0 ;
                 this -> v[i][j][k]. b = 0 ;
                 this -> v[i][j][k]. a = 0 ;
                 this -> v[i][j][k]. isOn = false ;
             }
         }
     }

}

Sculptor::~Sculptor (){ // liberação da memória alocada
    for ( int i= 0 ; i<nx; i++){
        for ( int j= 0 ; j<ny; j++){
            excluir [] v[i][j]; // liberação da ultima alocacao
        }
        excluir [] v[i]; // libertação da penúltima
    }
    excluir [] v; // liberação da primeira
}


void  Sculptor::setColor ( float vermelho, float verde, float azul, float alfa){
    // atribuicao das cores a partir dos parametros
    este -> r = vermelho;
    este -> g = verde;
    este -> b = azul;
    este -> a = alfa;

}

void  Escultor::putVoxel ( int x, int y, int z){
    // ativaçao de um unico voxel
    this -> v [x][y][z]. r = este -> r;
    this -> v [x][y][z]. g = este -> g;
    this -> v [x][y][z]. b = este -> b;
    this -> v [x][y][z]. a = isso -> a;
    this -> v [x][y][z]. isOn = true ;

}

void  Escultor::cutVoxel ( int x, int y, int z){
    this -> v [x][y][z]. isOn = false ; // desativação de uma unico voxel
}

// ativação de um bloco de voxels
void  Escultor::putBox ( int x0, int x1, int y0, int y1, int z0, int z1){
    if (( this -> nx >= x0 && this -> nx >= x1) && ( this -> ny >= y0 && this -> ny >= y1 ) && ( this -> nz >= z0 && this -> nz >= z1)){
        for ( int i = x0; i <x1; i++){
            for ( int j = y0 ; j < y1 ; j++){
                for ( int k = z0; k <z1; k++){
                    isto -> v [i][j][k]. r = este -> r;
                    isto -> v [i][j][k]. g = este -> g;
                    isto -> v [i][j][k]. b = este -> b;
                    isto -> v [i][j][k]. a = isso -> a;
                    isto -> v [i][j][k]. isOn = true ;
                }
            }
        }
    }

}
// desativação de um bloco de voxel
void  Escultor::cutBox ( int x0, int x1, int y0, int y1, int z0, int z1){
    if (( this -> nx >= x0 && this -> nx >= x1) && ( this -> ny >= y0 && this -> ny >= y1 ) && ( this -> nz >= z0 && this -> nz >= z1)){
     for ( int i = x0; i <x1; i++){
            for ( int j = y0 ; j < y1 ; j++){
                for ( int k = z0; k <z1; k++){
                    isto -> v [i][j][k]. isOn = false ;
                }
            }
        }
    }
}
// ativação de um bloco de voxels em forma de esfera
void  Sculptor::putSphere ( int xcenter, int ycenter, int zcenter, int radius){
         for ( int i = 0 ; i <nx; i++){
            for ( int j = 0 ; j < ny; j++){
                for ( int k = 0 ; k <nz; k++){
                   if (( pow (i-xcenter, 2 ) + pow (j-ycenter, 2 ) + pow (k-zcenter, 2 )) <= pow (raio, 2 )){
                        isto -> v [i][j][k]. r = este -> r;
                        isto -> v [i][j][k]. g = este -> g;
                        isto -> v [i][j][k]. b = este -> b;
                        isto -> v [i][j][k]. a = isso -> a;
                        isto -> v [i][j][k]. isOn = true ;
                    }
                }

            }

        }

}
// desativação de um bloco de voxels em forma de esfera
void  Sculptor::cutSphere ( int xcenter, int ycenter, int zcenter, int radius){
     for ( int i = 0 ; i <nx; i++){
            for ( int j = 0 ; j < ny; j++){
                for ( int k = 0 ; k <nz; k++){
                   if (( pow (i-xcenter, 2 ) + pow (j-ycenter, 2 ) + pow (k-zcenter, 2 )) <= pow (raio, 2 )){
                        isto -> v [i][j][k]. isOn = false ;
                    }
                }
            }
        }
}
// ativação de um bloco de voxels em forma de elipsoide
void  Sculptor::putElipsoid ( int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
     for ( int i = 0 ; i <nx; i++){
            for ( int j = 0 ; j < ny; j++){
                for ( int k = 0 ; k <nz; k++){
                   if ((( pow (i-xcenter, 2 )/ pow (rx, 2 )) + ( pow (j-ycenter, 2 )/ pow (ry, 2 ))+
                   ( pow (k-zcenter, 2 )/ pow (rz, 2 ))) <= 1 ){
                        isto -> v [i][j][k]. r = este -> r;
                        isto -> v [i][j][k]. g = este -> g;
                        isto -> v [i][j][k]. b = este -> b;
                        isto -> v [i][j][k]. a = isso -> a;
                        isto -> v [i][j][k]. isOn = true ;
                    }
                }

            }

        }
}

// desativação de um bloco de voxels em forma de elipsoide
void  Sculptor::cutElipsoid ( int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for ( int i = 0 ; i <nx; i++){
            for ( int j = 0 ; j < ny; j++){
                for ( int k = 0 ; k <nz; k++){
                   if ((( pow (i-xcenter, 2 )/ pow (rx, 2 )) + ( pow (j-ycenter, 2 )/ pow (ry, 2 ))+
                   ( pow (k-zcenter, 2 )/ pow (rz, 2 ))) <= 1 ){
                        isto -> v [i][j][k]. isOn = false ;
                    }
                }
            }
        }
}
// gravação do arquivo
void  Escultor::writeOFF ( char *nome do arquivo){
    int total_vox= 0 , cont_vox= 0 ;

    arquivo ofstream; // objeto da classe ofstream
    arquivo. abrir (nome do arquivo); // abrindo o fluxo para o arquivo

    for ( int i = 0 ; i < nx ; i++){
        for ( int j = 0 ; j < ny; j++){
            for ( int k = 0 ; k < nz; k++){
                if ( this -> v[i][j][k]. isOn == true ){
                        total_vox++;
                    }
                }
            }
        }

    arquivo << " OFF " << endl;
    arquivo << 8 * total_vox << "  " << 6 * total_vox << "  " << " 0 " << endl;

 // definindo as coordenadas dos vértices do voxel
    for ( int i = 0 ; i <nx; i++){
        for ( int j = 0 ; j <ny; j++){
            for ( int k = 0 ; k <nz; k++){
                  if ( this -> v [i][j][k]. isOn == true ){

                     arquivo << i - 0.5 << "  " << j + 0.5 << "  " << k - 0.5 << endl;
                     arquivo << i - 0.5 << "  " << j - 0.5 << "  " << k - 0.5 << endl;
                     arquivo << i + 0.5 << "  " << j - 0.5 << "  " << k - 0.5 << endl;
                     arquivo << i + 0.5 << "  " << j + 0.5 << "  " << k - 0.5 << endl;
                     arquivo << i - 0.5 << "  " << j + 0.5 << "  " << k + 0.5 << endl;
                     arquivo << i - 0.5 << "  " << j - 0.5 << "  " << k + 0.5 << endl;
                     arquivo << i + 0.5 << "  " << j - 0.5 << "  " << k + 0.5 << endl;
                     arquivo << i + 0.5 << "  " << j + 0.5 << "  " << k + 0.5 << endl;

                  }
                }
            }
        }
    // especificaçoes das faces e apresentacao das cores no formato RGBA
        for ( int i = 0 ; i <nx; i++){
            for ( int j = 0 ; j <ny; j++){
                for ( int k = 0 ; k <nz; k++){
                    if ( this -> v [i][j][k]. isOn == true ){

                        arquivo << " 4 " << "  " << 8 * cont_vox + 0 << "  " << 8 * cont_vox + 3 << "  " << 8 * cont_vox + 2 << "  "   << 8 * cont_vox + 1 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << " " << v [i][j][k]. a << endl;
                        arquivo << " 4 " << "  " << 8 * cont_vox + 4 << "  " << 8 * cont_vox + 5 << "  " << 8 * cont_vox + 6 << "  "   << 8 * cont_vox + 7 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << " " << v [i][j][k]. a << endl;
                        arquivo << " 4 " << "  " << 8 * cont_vox + 0 << "  " << 8 * cont_vox + 1 << "  " << 8 * cont_vox + 5 << "  "   << 8 * cont_vox + 4 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << " " << v [i][j][k]. a << endl;
                        arquivo << " 4 " << "  " << 8 * cont_vox + 0 << "  " << 8 * cont_vox + 4 << "  " << 8 * cont_vox + 7 << "  "   << 8 * cont_vox + 3 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << " " << v [i][j][k]. a << endl;
                        arquivo << " 4 " << "  " << 8 * cont_vox + 3 << "  " << 8 * cont_vox + 7 << "  " << 8 * cont_vox + 6 << "  "   << 8 * cont_vox + 2 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << " " << v [i][j][k]. a << endl;
                        arquivo << " 4 " << "  " << 8 * cont_vox + 1 << "  " << 8 * cont_vox + 2 << "  " << 8 * cont_vox + 6 << "  "   << 8 * cont_vox + 5 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << " " << v [i][j][k]. a << endl;

                        cont_vox++;

                    }
                }
            }
        }
  }
