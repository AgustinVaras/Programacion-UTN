<%@ Page Title="" Language="C#" MasterPageFile="~/MiMaster.Master" AutoEventWireup="true" CodeBehind="EjemploConMiMaster.aspx.cs" Inherits="Ejemplo1.EjemploConMiMaster" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h3 style="color:aquamarine">contenido de mi web con mi master</h3>
    <div>
        <asp:TextBox ID="txtNombre" runat="server"></asp:TextBox>
        <asp:Button ID="btnAceptar" runat="server" OnClick="btnAceptar_Click" Text="Aceptar" />
        <asp:Label style="color:aquamarine" ID="lblSaludo" runat="server" Text=""></asp:Label>
    </div>
</asp:Content>
