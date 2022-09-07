
namespace Ejemplo1
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnAgregar = new System.Windows.Forms.Button();
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.lwElementos = new System.Windows.Forms.ListView();
            this.lblNombre = new System.Windows.Forms.Label();
            this.lblFecha = new System.Windows.Forms.Label();
            this.dtpNacimiento = new System.Windows.Forms.DateTimePicker();
            this.ckbChocolate = new System.Windows.Forms.CheckBox();
            this.lblTitulo = new System.Windows.Forms.Label();
            this.gbTipo = new System.Windows.Forms.GroupBox();
            this.rbtWizard = new System.Windows.Forms.RadioButton();
            this.rbtMuggle = new System.Windows.Forms.RadioButton();
            this.rbtSquibs = new System.Windows.Forms.RadioButton();
            this.cboCasa = new System.Windows.Forms.ComboBox();
            this.lblCasa = new System.Windows.Forms.Label();
            this.numCampeonatos = new System.Windows.Forms.NumericUpDown();
            this.lblCampeonatos = new System.Windows.Forms.Label();
            this.btnVerPerfil = new System.Windows.Forms.Button();
            this.gbTipo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numCampeonatos)).BeginInit();
            this.SuspendLayout();
            // 
            // btnAgregar
            // 
            this.btnAgregar.Location = new System.Drawing.Point(63, 532);
            this.btnAgregar.Name = "btnAgregar";
            this.btnAgregar.Size = new System.Drawing.Size(115, 31);
            this.btnAgregar.TabIndex = 0;
            this.btnAgregar.Text = "Agregar";
            this.btnAgregar.UseVisualStyleBackColor = true;
            this.btnAgregar.Click += new System.EventHandler(this.button1_Click);
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(166, 67);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(200, 20);
            this.txtNombre.TabIndex = 1;
            // 
            // lwElementos
            // 
            this.lwElementos.HideSelection = false;
            this.lwElementos.Location = new System.Drawing.Point(63, 382);
            this.lwElementos.Name = "lwElementos";
            this.lwElementos.Size = new System.Drawing.Size(171, 126);
            this.lwElementos.TabIndex = 2;
            this.lwElementos.UseCompatibleStateImageBehavior = false;
            this.lwElementos.View = System.Windows.Forms.View.List;
            // 
            // lblNombre
            // 
            this.lblNombre.AutoSize = true;
            this.lblNombre.Location = new System.Drawing.Point(109, 70);
            this.lblNombre.Name = "lblNombre";
            this.lblNombre.Size = new System.Drawing.Size(47, 13);
            this.lblNombre.TabIndex = 3;
            this.lblNombre.Text = "Nombre:";
            // 
            // lblFecha
            // 
            this.lblFecha.AutoSize = true;
            this.lblFecha.Location = new System.Drawing.Point(60, 104);
            this.lblFecha.Name = "lblFecha";
            this.lblFecha.Size = new System.Drawing.Size(96, 13);
            this.lblFecha.TabIndex = 4;
            this.lblFecha.Text = "Fecha Nacimiento:";
            // 
            // dtpNacimiento
            // 
            this.dtpNacimiento.Location = new System.Drawing.Point(166, 104);
            this.dtpNacimiento.Name = "dtpNacimiento";
            this.dtpNacimiento.Size = new System.Drawing.Size(200, 20);
            this.dtpNacimiento.TabIndex = 5;
            // 
            // ckbChocolate
            // 
            this.ckbChocolate.AutoSize = true;
            this.ckbChocolate.Location = new System.Drawing.Point(166, 144);
            this.ckbChocolate.Name = "ckbChocolate";
            this.ckbChocolate.Size = new System.Drawing.Size(135, 17);
            this.ckbChocolate.TabIndex = 6;
            this.ckbChocolate.Text = "Te gusta el chocolate?";
            this.ckbChocolate.UseVisualStyleBackColor = true;
            // 
            // lblTitulo
            // 
            this.lblTitulo.AutoSize = true;
            this.lblTitulo.Font = new System.Drawing.Font("Arial Narrow", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitulo.Location = new System.Drawing.Point(58, 27);
            this.lblTitulo.Name = "lblTitulo";
            this.lblTitulo.Size = new System.Drawing.Size(142, 25);
            this.lblTitulo.TabIndex = 7;
            this.lblTitulo.Text = "Perfil Persona: ";
            // 
            // gbTipo
            // 
            this.gbTipo.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.gbTipo.Controls.Add(this.rbtSquibs);
            this.gbTipo.Controls.Add(this.rbtMuggle);
            this.gbTipo.Controls.Add(this.rbtWizard);
            this.gbTipo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbTipo.Location = new System.Drawing.Point(112, 167);
            this.gbTipo.Name = "gbTipo";
            this.gbTipo.Size = new System.Drawing.Size(294, 70);
            this.gbTipo.TabIndex = 8;
            this.gbTipo.TabStop = false;
            this.gbTipo.Text = "Tipo: ";
            // 
            // rbtWizard
            // 
            this.rbtWizard.AutoSize = true;
            this.rbtWizard.Location = new System.Drawing.Point(43, 31);
            this.rbtWizard.Name = "rbtWizard";
            this.rbtWizard.Size = new System.Drawing.Size(58, 17);
            this.rbtWizard.TabIndex = 0;
            this.rbtWizard.TabStop = true;
            this.rbtWizard.Text = "Wizard";
            this.rbtWizard.UseVisualStyleBackColor = true;
            // 
            // rbtMuggle
            // 
            this.rbtMuggle.AutoSize = true;
            this.rbtMuggle.Location = new System.Drawing.Point(129, 31);
            this.rbtMuggle.Name = "rbtMuggle";
            this.rbtMuggle.Size = new System.Drawing.Size(60, 17);
            this.rbtMuggle.TabIndex = 1;
            this.rbtMuggle.TabStop = true;
            this.rbtMuggle.Text = "Muggle";
            this.rbtMuggle.UseVisualStyleBackColor = true;
            // 
            // rbtSquibs
            // 
            this.rbtSquibs.AutoSize = true;
            this.rbtSquibs.Location = new System.Drawing.Point(213, 31);
            this.rbtSquibs.Name = "rbtSquibs";
            this.rbtSquibs.Size = new System.Drawing.Size(57, 17);
            this.rbtSquibs.TabIndex = 2;
            this.rbtSquibs.TabStop = true;
            this.rbtSquibs.Text = "Squibs";
            this.rbtSquibs.UseVisualStyleBackColor = true;
            // 
            // cboCasa
            // 
            this.cboCasa.FormattingEnabled = true;
            this.cboCasa.Location = new System.Drawing.Point(166, 256);
            this.cboCasa.Name = "cboCasa";
            this.cboCasa.Size = new System.Drawing.Size(200, 21);
            this.cboCasa.TabIndex = 9;
            // 
            // lblCasa
            // 
            this.lblCasa.AutoSize = true;
            this.lblCasa.Location = new System.Drawing.Point(122, 259);
            this.lblCasa.Name = "lblCasa";
            this.lblCasa.Size = new System.Drawing.Size(34, 13);
            this.lblCasa.TabIndex = 10;
            this.lblCasa.Text = "Casa:";
            // 
            // numCampeonatos
            // 
            this.numCampeonatos.Location = new System.Drawing.Point(166, 300);
            this.numCampeonatos.Name = "numCampeonatos";
            this.numCampeonatos.Size = new System.Drawing.Size(200, 20);
            this.numCampeonatos.TabIndex = 11;
            // 
            // lblCampeonatos
            // 
            this.lblCampeonatos.AutoSize = true;
            this.lblCampeonatos.Location = new System.Drawing.Point(33, 302);
            this.lblCampeonatos.Name = "lblCampeonatos";
            this.lblCampeonatos.Size = new System.Drawing.Size(123, 13);
            this.lblCampeonatos.TabIndex = 12;
            this.lblCampeonatos.Text = "Campeonatos Quidditch:";
            // 
            // btnVerPerfil
            // 
            this.btnVerPerfil.Location = new System.Drawing.Point(63, 345);
            this.btnVerPerfil.Name = "btnVerPerfil";
            this.btnVerPerfil.Size = new System.Drawing.Size(75, 23);
            this.btnVerPerfil.TabIndex = 13;
            this.btnVerPerfil.Text = "Ver Perfil";
            this.btnVerPerfil.UseVisualStyleBackColor = true;
            this.btnVerPerfil.Click += new System.EventHandler(this.btnVerPerfil_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(557, 576);
            this.Controls.Add(this.btnVerPerfil);
            this.Controls.Add(this.lblCampeonatos);
            this.Controls.Add(this.numCampeonatos);
            this.Controls.Add(this.lblCasa);
            this.Controls.Add(this.cboCasa);
            this.Controls.Add(this.gbTipo);
            this.Controls.Add(this.lblTitulo);
            this.Controls.Add(this.ckbChocolate);
            this.Controls.Add(this.dtpNacimiento);
            this.Controls.Add(this.lblFecha);
            this.Controls.Add(this.lblNombre);
            this.Controls.Add(this.lwElementos);
            this.Controls.Add(this.txtNombre);
            this.Controls.Add(this.btnAgregar);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.gbTipo.ResumeLayout(false);
            this.gbTipo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numCampeonatos)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnAgregar;
        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.ListView lwElementos;
        private System.Windows.Forms.Label lblNombre;
        private System.Windows.Forms.Label lblFecha;
        private System.Windows.Forms.DateTimePicker dtpNacimiento;
        private System.Windows.Forms.CheckBox ckbChocolate;
        private System.Windows.Forms.Label lblTitulo;
        private System.Windows.Forms.GroupBox gbTipo;
        private System.Windows.Forms.RadioButton rbtSquibs;
        private System.Windows.Forms.RadioButton rbtMuggle;
        private System.Windows.Forms.RadioButton rbtWizard;
        private System.Windows.Forms.ComboBox cboCasa;
        private System.Windows.Forms.Label lblCasa;
        private System.Windows.Forms.NumericUpDown numCampeonatos;
        private System.Windows.Forms.Label lblCampeonatos;
        private System.Windows.Forms.Button btnVerPerfil;
    }
}

