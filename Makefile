# --------------------------------------------------------------------
# Makefile Lab0 - Programación 4
# --------------------------------------------------------------------

all: principal

.PHONY: all clean clean_bin entrega claves

ARCHIVO_ENTREGA=EntregaLab0.tar.gz

# Módulos que tienen archivo .cpp y .hpp
MODULOS = Alojamiento DTExpe DTFecha EventoCultural Experiencia TourGuiado Turista

# Directorios
HDIR    = include
CPPDIR  = src
ODIR    = obj

# Extensiones
EXT = cpp
HEXT = hpp

# Compilador y opciones
CC = g++
LD = g++
# -I$(HDIR) es fundamental para que encuentre los .hpp dentro de /include
CCFLAGS = -Wall -Werror -I$(HDIR) -g

# Definición de archivos de objetos
OS = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL=principal
EJECUTABLE=principal

ARCHIVO_CLAVES=claves.txt
COMANDO_CLAVES=shasum

# --- Reglas de Compilación ---

# Compila el principal.cpp que está en la raíz
$(ODIR)/$(PRINCIPAL).o: $(PRINCIPAL).$(EXT)
	@mkdir -p $(ODIR)
	@printf 'Compilando principal... \n'
	$(CC) $(CCFLAGS) -c $< -o $@

# Compila los módulos de /src
$(ODIR)/%.o: $(CPPDIR)/%.$(EXT) $(HDIR)/%.$(HEXT)
	@mkdir -p $(ODIR)
	@printf 'Compilando módulo $*... \n'
	$(CC) $(CCFLAGS) -c $< -o $@

# Enlaza todo para crear el ejecutable
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	@printf 'Enlazando $(EJECUTABLE)... \n'
	$(LD) $(CCFLAGS) $^ -o $@

# --- Regla de Entrega (sin pruebas) ---

$(ARCHIVO_CLAVES):
	@rm -f $@
	@printf 'Generando claves... \n'
	# Genera claves solo de los .cpp para el control de integridad
	@$(COMANDO_CLAVES) $(PRINCIPAL).$(EXT) $(MODULOS:%=$(CPPDIR)/%.$(EXT)) > $@

entrega: $(ARCHIVO_CLAVES)
	@rm -f $(ARCHIVO_ENTREGA)
	# Crea el tar.gz incluyendo la estructura necesaria para que el prof haga make
	tar zcf $(ARCHIVO_ENTREGA) Makefile $(ARCHIVO_CLAVES) $(PRINCIPAL).$(EXT) include/ src/
	@echo "-------------------------------------------------------"
	@echo "Archivo generado: $(ARCHIVO_ENTREGA)"
	@echo "Contenido: Makefile, principal.cpp, carpeta include y carpeta src."
	@echo "-------------------------------------------------------"

# --- Limpieza ---

clean_bin:
	@rm -rf $(ODIR) $(EJECUTABLE)

clean: clean_bin
	@rm -f $(ARCHIVO_ENTREGA) $(ARCHIVO_CLAVES)