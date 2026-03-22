# --------------------------------------------------------------------
# Makefile adaptado para Lab0 - Programación 4
# Sin casos de prueba activos y con soporte para .hpp
# --------------------------------------------------------------------

all: principal

.PHONY: all clean_bin clean_test clean testing entrega claves

ARCHIVO_ENTREGA=EntregaLab0.tar.gz

# --- Módulos a entregar para Lab0 ---
# Ajusta estos nombres según los archivos .cpp que tengas en /src
ENTREGAR = Experiencia Turista Alojamiento Sistema

MODULOS = $(ENTREGAR) utils

# Directorios
HDIR    = include
CPPDIR  = src
ODIR    = obj
INDIR   = test
OUTDIR  = test
SALIDADIR = test/salidas

# Extensiones
EXT = cpp
HEXT = hpp

# Compilador y opciones
CC = g++
LD = g++
# Se incluye -I$(HDIR) para que encuentre los .hpp
CCFLAGS = -Wall -Werror -I$(HDIR) -g

# Definición de archivos
HS   = $(MODULOS:%=$(HDIR)/%.$(HEXT))
CPPS = $(MODULOS:%=$(CPPDIR)/%.$(EXT))
OS   = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL=principal
EJECUTABLE=principal

ARCHIVO_CLAVES=claves.txt
COMANDO_CLAVES=shasum

# --- Reglas de Compilación ---

$(ODIR)/$(PRINCIPAL).o:$(PRINCIPAL).$(EXT)
	@mkdir -p $(ODIR)
	@printf 'Compilando $(<) \n'; \
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: $(CPPDIR)/%.$(EXT) $(HDIR)/%.$(HEXT)
	@mkdir -p $(ODIR)
	@printf 'Compilando $(<) \n'; \
	$(CC) $(CCFLAGS) -c $< -o $@

$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	@printf 'Compilando y enlazando $(@) \n'; \
	$(LD) $(CCFLAGS) $^ -o $@

# --- Casos de Prueba (Vacíos para esta entrega) ---

CASOS = 

# Las reglas de test se mantienen estructuralmente pero no harán nada si CASOS está vacío
$(SALIDADIR)/%.sal: $(INDIR)/%.in $(EJECUTABLE)
	@mkdir -p $(SALIDADIR)

testing: all
	@echo "No hay casos de prueba definidos para esta entrega."

# --- Entrega ---

$(ARCHIVO_CLAVES):
	@rm -f $@
	@printf 'Generando claves de entrega... \n'; \
	$(COMANDO_CLAVES) $(ENTREGAR:%=$(CPPDIR)/%.$(EXT)) > $@

claves: $(ARCHIVO_CLAVES)

# Genera el .tar.gz con los .cpp y el archivo de claves
entrega: claves
	@rm -f $(ARCHIVO_ENTREGA)
	tar zcf $(ARCHIVO_ENTREGA) $(ARCHIVO_CLAVES) -C src $(ENTREGAR:%=%.$(EXT))
	@echo -- El archivo a entregar ha sido generado:
	@echo $$(pwd)/$(ARCHIVO_ENTREGA)

# --- Limpieza ---

clean_bin:
	@rm -f $(EJECUTABLE) $(ODIR)/*.o

clean_test:
	@rm -rf $(SALIDADIR)

clean: clean_test clean_bin
	@rm -f $(ARCHIVO_ENTREGA) $(ARCHIVO_CLAVES) *~ $(HDIR)/*~ $(CPPDIR)/*~