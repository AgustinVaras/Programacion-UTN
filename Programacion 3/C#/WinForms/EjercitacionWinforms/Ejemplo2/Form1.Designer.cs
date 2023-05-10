
namespace Ejemplo2
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
            this.lwNombres = new System.Windows.Forms.ListView();
            this.lblNombre = new System.Windows.Forms.Label();
            this.lblFecha = new System.Windows.Forms.Label();
            this.dtpNacimiento = new System.Windows.Forms.DateTimePicker();
            this.ckbChocolate = new System.Windows.Forms.CheckBox();
            this.lblPerfil = new System.Windows.Forms.Label();
            this.grbCasas = new System.Windows.Forms.GroupBox();
            this.rdbGryffindor = new System.Windows.Forms.RadioButton();
            this.rdbRavenclaw = new System.Windows.Forms.RadioButton();
            this.rdbHufflepuff = new System.Windows.Forms.RadioButton();
            this.rdbSlytherin = new System.Windows.Forms.RadioButton();
            this.lblOrigen = new System.Windows.Forms.Label();
            this.cboOrigen = new System.Windows.Forms.ComboBox();
            this.btnPerfil = new System.Windows.Forms.Button();
            this.grbCasas.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnAgregar
            // 
            this.btnAgregar.Location = new System.Drawing.Point(61, 503);
            this.btnAgregar.Name = "btnAgregar";
            this.btnAgregar.Size = new System.Drawing.Size(75, 23);
            this.btnAgregar.TabIndex = 0;
            this.btnAgregar.Text = "Agregar";
            this.btnAgregar.UseVisualStyleBackColor = true;
            this.btnAgregar.Click += new System.EventHandler(this.btnAgregar_Click);
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(130, 106);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(130, 20);
            this.txtNombre.TabIndex = 1;
            // 
            // lwNombres
            // 
            this.lwNombres.HideSelection = false;
            this.lwNombres.Location = new System.Drawing.Point(61, 353);
            this.lwNombres.Name = "lwNombres";
            this.lwNombres.Size = new System.Drawing.Size(192, 124);
            this.lwNombres.TabIndex = 2;
            this.lwNombres.UseCompatibleStateImageBehavior = false;
            this.lwNombres.View = System.Windows.Forms.View.List;
            // 
            // lblNombre
            // 
            this.lblNombre.AutoSize = true;
            this.lblNombre.Location = new System.Drawing.Point(74, 109);
            this.lblNombre.Name = "lblNombre";
            this.lblNombre.Size = new System.Drawing.Size(50, 13);
            this.lblNombre.TabIndex = 3;
            this.lblNombre.Text = "Nombre: ";
            // 
            // lblFecha
            // 
            this.lblFecha.AutoSize = true;
            this.lblFecha.Location = new System.Drawing.Point(58, 151);
            this.lblFecha.Name = "lblFecha";
            this.lblFecha.Size = new System.Drawing.Size(66, 13);
            this.lblFecha.TabIndex = 4;
            this.lblFecha.Text = "Nacimiento: ";
            // 
            // dtpNacimiento
            // 
            this.dtpNacimiento.Location = new System.Drawing.Point(131, 151);
            this.dtpNacimiento.Name = "dtpNacimiento";
            this.dtpNacimiento.Size = new System.Drawing.Size(201, 20);
            this.dtpNacimiento.TabIndex = 5;
            // 
            // ckbChocolate
            // 
            this.ckbChocolate.AutoSize = true;
            this.ckbChocolate.Location = new System.Drawing.Point(125, 192);
            this.ckbChocolate.Name = "ckbChocolate";
            this.ckbChocolate.Size = new System.Drawing.Size(135, 17);
            this.ckbChocolate.TabIndex = 6;
            this.ckbChocolate.Text = "Te gusta el chocolate?";
            this.ckbChocolate.UseVisualStyleBackColor = true;
            // 
            // lblPerfil
            // 
            this.lblPerfil.AutoSize = true;
            this.lblPerfil.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPerfil.Location = new System.Drawing.Point(71, 37);
            this.lblPerfil.Name = "lblPerfil";
            this.lblPerfil.Size = new System.Drawing.Size(82, 31);
            this.lblPerfil.TabIndex = 7;
            this.lblPerfil.Text = "Perfil";
            // 
            // grbCasas
            // 
            this.grbCasas.Controls.Add(this.rdbSlytherin);
            this.grbCasas.Controls.Add(this.rdbHufflepuff);
            this.grbCasas.Controls.Add(this.rdbRavenclaw);
            this.grbCasas.Controls.Add(this.rdbGryffindor);
            this.grbCasas.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.grbCasas.Location = new System.Drawing.Point(61, 215);
            this.grbCasas.Name = "grbCasas";
            this.grbCasas.Size = new System.Drawing.Size(231, 97);
            this.grbCasas.TabIndex = 8;
            this.grbCasas.TabStop = false;
            this.grbCasas.Text = "Casas";
            // 
            // rdbGryffindor
            // 
            this.rdbGryffindor.AutoSize = true;
            this.rdbGryffindor.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdbGryffindor.Location = new System.Drawing.Point(16, 19);
            this.rdbGryffindor.Name = "rdbGryffindor";
            this.rdbGryffindor.Size = new System.Drawing.Size(77, 19);
            this.rdbGryffindor.TabIndex = 0;
            this.rdbGryffindor.TabStop = true;
            this.rdbGryffindor.Text = "Gryffindor";
            this.rdbGryffindor.UseVisualStyleBackColor = true;
            // 
            // rdbRavenclaw
            // 
            this.rdbRavenclaw.AutoSize = true;
            this.rdbRavenclaw.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdbRavenclaw.Location = new System.Drawing.Point(117, 19);
            this.rdbRavenclaw.Name = "rdbRavenclaw";
            this.rdbRavenclaw.Size = new System.Drawing.Size(85, 19);
            this.rdbRavenclaw.TabIndex = 1;
            this.rdbRavenclaw.TabStop = true;
            this.rdbRavenclaw.Text = "Ravenclaw";
            this.rdbRavenclaw.UseVisualStyleBackColor = true;
            // 
            // rdbHufflepuff
            // 
            this.rdbHufflepuff.AutoSize = true;
            this.rdbHufflepuff.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdbHufflepuff.Location = new System.Drawing.Point(16, 60);
            this.rdbHufflepuff.Name = "rdbHufflepuff";
            this.rdbHufflepuff.Size = new System.Drawing.Size(77, 19);
            this.rdbHufflepuff.TabIndex = 2;
            this.rdbHufflepuff.TabStop = true;
            this.rdbHufflepuff.Text = "Hufflepuff";
            this.rdbHufflepuff.UseVisualStyleBackColor = true;
            // 
            // rdbSlytherin
            // 
            this.rdbSlytherin.AutoSize = true;
            this.rdbSlytherin.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rdbSlytherin.Location = new System.Drawing.Point(117, 60);
            this.rdbSlytherin.Name = "rdbSlytherin";
            this.rdbSlytherin.Size = new System.Drawing.Size(72, 19);
            this.rdbSlytherin.TabIndex = 3;
            this.rdbSlytherin.TabStop = true;
            this.rdbSlytherin.Text = "Slytherin";
            this.rdbSlytherin.UseVisualStyleBackColor = true;
            // 
            // lblOrigen
            // 
            this.lblOrigen.AutoSize = true;
            this.lblOrigen.Location = new System.Drawing.Point(53, 328);
            this.lblOrigen.Name = "lblOrigen";
            this.lblOrigen.Size = new System.Drawing.Size(44, 13);
            this.lblOrigen.TabIndex = 9;
            this.lblOrigen.Text = "Origen: ";
            // 
            // cboOrigen
            // 
            this.cboOrigen.FormattingEnabled = true;
            this.cboOrigen.Location = new System.Drawing.Point(103, 325);
            this.cboOrigen.Name = "cboOrigen";
            this.cboOrigen.Size = new System.Drawing.Size(150, 21);
            this.cboOrigen.TabIndex = 10;
            // 
            // btnPerfil
            // 
            this.btnPerfil.Location = new System.Drawing.Point(175, 503);
            this.btnPerfil.Name = "btnPerfil";
            this.btnPerfil.Size = new System.Drawing.Size(75, 23);
            this.btnPerfil.TabIndex = 11;
            this.btnPerfil.Text = "Ver Perfil";
            this.btnPerfil.UseVisualStyleBackColor = true;
            this.btnPerfil.Click += new System.EventHandler(this.btnPerfil_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(372, 624);
            this.Controls.Add(this.btnPerfil);
            this.Controls.Add(this.cboOrigen);
            this.Controls.Add(this.lblOrigen);
            this.Controls.Add(this.grbCasas);
            this.Controls.Add(this.lblPerfil);
            this.Controls.Add(this.ckbChocolate);
            this.Controls.Add(this.dtpNacimiento);
            this.Controls.Add(this.lblFecha);
            this.Controls.Add(this.lblNombre);
            this.Controls.Add(this.lwNombres);
            this.Controls.Add(this.txtNombre);
            this.Controls.Add(this.btnAgregar);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.grbCasas.ResumeLayout(false);
            this.grbCasas.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnAgregar;
        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.ListView lwNombres;
        private System.Windows.Forms.Label lblNombre;
        private System.Windows.Forms.Label lblFecha;
        private System.Windows.Forms.DateTimePicker dtpNacimiento;
        private System.Windows.Forms.CheckBox ckbChocolate;
        private System.Windows.Forms.Label lblPerfil;
        private System.Windows.Forms.GroupBox grbCasas;
        private System.Windows.Forms.RadioButton rdbSlytherin;
        private System.Windows.Forms.RadioButton rdbHufflepuff;
        private System.Windows.Forms.RadioButton rdbRavenclaw;
        private System.Windows.Forms.RadioButton rdbGryffindor;
        private System.Windows.Forms.Label lblOrigen;
        private System.Windows.Forms.ComboBox cboOrigen;
        private System.Windows.Forms.Button btnPerfil;
    }
}

