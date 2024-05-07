//***************************************************************************************/
//MIT License

//Copyright (c) 2017 CTCaer

//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.
//***************************************************************************************/

#pragma once
namespace Overrides {
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class TestColorTable : ProfessionalColorTable {
        public: property Color ToolStripDropDownBackground
        {
            virtual Color get() override {
                return Color::FromArgb(55, 55, 55);
            }
        }

        public: property Color MenuItemSelected
        {
            virtual Color get() override {
                return Color::FromArgb(85, 85, 85);
            }
        }

        public: property Color MenuBorder
        {
            virtual Color get() override {
                return Color::FromArgb(55, 55, 55);
            }
        }

        public: property Color MenuItemBorder
        {
            virtual Color get() override {
                return Color::FromArgb(70, 70, 70);
            }
        }

        public: property Color MenuItemPressedGradientBegin
        {
            virtual Color get() override {
                return Color::FromArgb(85, 85, 85);
            }
        }

        public: property Color MenuItemPressedGradientEnd
        {
            virtual Color get() override {
                return Color::FromArgb(85, 85, 85);
            }
        }

        public: property Color ImageMarginGradientBegin
        {
            virtual Color get() override {
                return Color::FromArgb(55, 55, 55);
            }
        }

        public: property Color ImageMarginGradientEnd
        {
            virtual Color get() override {
                return Color::FromArgb(55, 55, 55);
            }
        }

        public: property Color MenuItemSelectedGradientBegin
        {
            virtual Color get() override {
                return Color::FromArgb(85, 85, 85);
            }
        }

        public: property Color MenuItemSelectedGradientEnd
        {
            virtual Color get() override {
                return Color::FromArgb(85, 85, 85);
            }
        }

    };

    public ref class OverrideTSSR : ToolStripSystemRenderer {
        public: OverrideTSSR() {}

        protected: virtual void OnRenderToolStripBorder(ToolStripRenderEventArgs^ e) override {
            // Do nothing
        }
    };

}