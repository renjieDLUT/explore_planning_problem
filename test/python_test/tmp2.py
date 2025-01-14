import tkinter as tk  

from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg  

from matplotlib.figure import Figure  

  

class App(tk.Tk):  

    def __init__(self):  

        super().__init__()  

        self.title("Matplotlib in Tkinter with Button")  

          

        # 创建一个Matplotlib Figure和Axes  

        self.fig = Figure(figsize=(5, 4), dpi=100)  

        self.ax = self.fig.add_subplot(111)  

        self.plot_something()  

          

        # 将Matplotlib图形嵌入到Tkinter的Frame中  

        self.canvas = FigureCanvasTkAgg(self.fig, master=self)  

        self.canvas_widget = self.canvas.get_tk_widget()  # 这是Tkinter的Canvas部件  

        self.canvas_widget.pack(side=tk.TOP, fill=tk.BOTH, expand=True)  

          

        # 创建一个按钮并添加到Tkinter的Frame中  

        self.button = tk.Button(self, text="Update Plot", command=self.update_plot)  

        self.button.pack(side=tk.BOTTOM)  

      

    def plot_something(self):  

        # 示例：在Axes上绘制一些内容  

        self.ax.clear()  # 清除旧的绘图  

        self.ax.plot([0, 1, 2, 3], [0, 1, 4, 9])  

        self.canvas.draw()  # 更新Tkinter Canvas上的图形  

      

    def update_plot(self):  

        # 当按钮被点击时，更新Matplotlib图形  

        self.plot_something()  # 这里可以添加不同的绘图逻辑  

  

if __name__ == "__main__":  

    app = App()  

    app.mainloop()