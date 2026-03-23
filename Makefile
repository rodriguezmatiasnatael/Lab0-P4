# --------------------------------------------------------------------
# Makefile Lab0 - Programación 4 (Facultad de Ingeniería)
# --------------------------------------------------------------------

# Módulos que tienen archivo .cpp y .hpp
MODULOS = Alojamiento DTExpe DTFecha EventoCultural Experiencia TourGuiado Turista

# Directorios
HDIR    = include
CPPDIR  = src
ODIR    = obj

# Compilador y opciones
CC = g++
LD = g++

# Banderas obligatorias: -std=c++98 para compatibilidad total
CXXFLAGS = -Wall -Werror -I$(HDIR) -g -std=c++98

# Definición de archivos de objetos
OS = $(MODULOS:%=$(ODIR)/%.o)
PRINCIPAL = principal
EJECUTABLE = principal

all: $(EJECUTABLE)

# Compila el principal.cpp que está en la raíz
$(ODIR)/$(PRINCIPAL).o: $(PRINCIPAL).cpp
	@mkdir -p $(ODIR)
	@printf 'Compilando principal... \n'
	$(CC) $(CCFLAGS) -c $< -o $@

# Compila los módulos de /src
# Se eliminó la dependencia rígida de .hpp para evitar errores si algún módulo no tiene
$(ODIR)/%.o: $(CPPDIR)/%.cpp
	@mkdir -p $(ODIR)
	@printf 'Compilando módulo $*... \n'
	$(CC) $(CCFLAGS) -c $< -o $@

# Enlaza todo para crear el ejecutable
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	@printf 'Enlazando $(EJECUTABLE)... \n'
	$(LD) $(CCFLAGS) $^ -o $@

# --- Limpieza ---
clean:
	@rm -rf $(ODIR) $(EJECUTABLE) EntregaLab0.tar.gz claves.txt

.PHONY: all clean